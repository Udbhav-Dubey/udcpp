#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>
#include <algorithm>
#include <string>
#include <sstream>
#ifdef _WIN32
    #include <winsock2.h>
    #include <ws2tcpip.h>
    #pragma comment(lib, "ws2_32.lib")
#else
    #include <sys/socket.h>
    #include <netinet/in.h>
    #include <unistd.h>
    #include <signal.h>
#endif

using namespace std;
using namespace std::chrono;

// Game state - keeping it simple and clean
const int WIDTH = 21;
const int HEIGHT = 21;

struct GameState {
    vector<vector<char>> maze;
    int playerX, playerY;
    int bot1X, bot1Y;
    int bot2X, bot2Y;
    int exitX, exitY;
    bool gameActive;
    steady_clock::time_point startTime;
    int timeLimit = 120;
    
    GameState() : maze(HEIGHT, vector<char>(WIDTH, '|')), 
                  playerX(1), playerY(1), gameActive(false) {}
};

GameState game;

const vector<pair<int,int>> directions = {
    {-2, 0}, {2, 0}, {0, 2}, {0, -2}
};

bool isValid(int x, int y) {
    return x > 0 && x < HEIGHT - 1 && y > 0 && y < WIDTH - 1;
}

void carveMaze(int x, int y) {
    game.maze[x][y] = ' ';
    vector<pair<int,int>> dirs = directions;
    random_device rd;
    mt19937 g(rd());
    shuffle(dirs.begin(), dirs.end(), g);
    
    for (auto [dx, dy] : dirs) {
        int nx = x + dx;
        int ny = y + dy;
        
        if (isValid(nx, ny) && game.maze[nx][ny] == '|') {
            game.maze[x + dx/2][y + dy/2] = ' ';
            carveMaze(nx, ny);
        }
    }
}

void placeExit() {
    vector<pair<int,int>> possibleExits;
    
    for (int i = 1; i < WIDTH - 1; ++i) {
        if (game.maze[1][i] == ' ') possibleExits.push_back({0, i});
        if (game.maze[HEIGHT - 2][i] == ' ') possibleExits.push_back({HEIGHT - 1, i});
    }
    for (int i = 1; i < HEIGHT - 1; ++i) {
        if (game.maze[i][1] == ' ') possibleExits.push_back({i, 0});
        if (game.maze[i][WIDTH - 2] == ' ') possibleExits.push_back({i, WIDTH - 1});
    }
    
    if (!possibleExits.empty()) {
        random_device rd;
        mt19937 g(rd());
        uniform_int_distribution<> dis(0, possibleExits.size() - 1);
        tie(game.exitX, game.exitY) = possibleExits[dis(g)];
    }
}

void placeBots() {
    vector<pair<int,int>> emptyCells;
    for (int i = 1; i < HEIGHT - 1; ++i) {
        for (int j = 1; j < WIDTH - 1; ++j) {
            if (game.maze[i][j] == ' ' && 
                !(i == 1 && j == 1) && 
                !(i == game.exitX && j == game.exitY)) {
                emptyCells.push_back({i, j});
            }
        }
    }
    
    if (emptyCells.size() >= 2) {
        random_device rd;
        mt19937 g(rd());
        shuffle(emptyCells.begin(), emptyCells.end(), g);
        
        // Place bot1
        tie(game.bot1X, game.bot1Y) = emptyCells[0];
        // Place bot2
        tie(game.bot2X, game.bot2Y) = emptyCells[1];
    }
}

void moveBots() {
    if (!game.gameActive) return;
    
    vector<pair<int,int>> dirs = directions;
    random_device rd;
    mt19937 g(rd());
    
    // Move Bot1
    shuffle(dirs.begin(), dirs.end(), g);
    for (auto [dx, dy] : dirs) {
        int nx = game.bot1X + dx;
        int ny = game.bot1Y + dy;
        
        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH) {
            if (game.maze[nx][ny] == ' ' || (nx == game.playerX && ny == game.playerY)) {
                game.bot1X = nx;
                game.bot1Y = ny;
                break;
            }
        }
    }
    
    // Move Bot2 (same logic, independent movement)
    shuffle(dirs.begin(), dirs.end(), g);
    for (auto [dx, dy] : dirs) {
        int nx = game.bot2X + dx;
        int ny = game.bot2Y + dy;
        
        if (nx >= 0 && nx < HEIGHT && ny >= 0 && ny < WIDTH) {
            if (game.maze[nx][ny] == ' ' || (nx == game.playerX && ny == game.playerY)) {
                game.bot2X = nx;
                game.bot2Y = ny;
                break;
            }
        }
    }
}

void initNewGame() {
    // Reset everything
    game.maze.assign(HEIGHT, vector<char>(WIDTH, '|'));
    game.playerX = 1;
    game.playerY = 1;
    game.gameActive = true;
    game.startTime = steady_clock::now();
    
    // Generate new maze
    carveMaze(1, 1);
    placeExit();
    placeBots();
    
    cout << "New game started with 2 bots!" << endl;
}

string getMazeJson() {
    string json = "{\"maze\":[";
    
    for (int i = 0; i < HEIGHT; ++i) {
        json += "[";
        for (int j = 0; j < WIDTH; ++j) {
            char cell = game.maze[i][j];
            
            // Override with current positions
            if (i == game.playerX && j == game.playerY) {
                cell = 'P';
            } else if (i == game.bot1X && j == game.bot1Y && game.gameActive) {
                cell = '1';  // Bot1 shows as '1'
            } else if (i == game.bot2X && j == game.bot2Y && game.gameActive) {
                cell = '2';  // Bot2 shows as '2'
            } else if (i == game.exitX && j == game.exitY) {
                cell = 'E';
            }
            
            json += "\"" + string(1, cell) + "\"";
            if (j < WIDTH - 1) json += ",";
        }
        json += "]";
        if (i < HEIGHT - 1) json += ",";
    }
    
    // Calculate remaining time
    auto now = steady_clock::now();
    int elapsed = duration_cast<seconds>(now - game.startTime).count();
    int remaining = max(0, game.timeLimit - elapsed);
    
    // Check if time's up
    if (remaining <= 0 && game.gameActive) {
        game.gameActive = false;
    }
    
    json += "],";
    json += "\"timeRemaining\":" + to_string(remaining) + ",";
    json += "\"playerX\":" + to_string(game.playerX) + ",";
    json += "\"playerY\":" + to_string(game.playerY) + ",";
    json += "\"bot1X\":" + to_string(game.bot1X) + ",";
    json += "\"bot1Y\":" + to_string(game.bot1Y) + ",";
    json += "\"bot2X\":" + to_string(game.bot2X) + ",";
    json += "\"bot2Y\":" + to_string(game.bot2Y) + ",";
    json += "\"exitX\":" + to_string(game.exitX) + ",";
    json += "\"exitY\":" + to_string(game.exitY) + ",";
    json += "\"gameActive\":" + string(game.gameActive ? "true" : "false");
    json += "}";
    
    return json;
}

string handleRequest(const string& request) {
    string headers = "HTTP/1.1 200 OK\r\n"
                    "Content-Type: application/json\r\n"
                    "Access-Control-Allow-Origin: *\r\n"
                    "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
                    "Access-Control-Allow-Headers: Content-Type\r\n\r\n";
    
    cout << "Request: " << request.substr(0, 50) << "..." << endl;
    
    if (request.find("OPTIONS") == 0) {
        return headers + "{}";
    }
    
    if (request.find("GET /newgame") != string::npos) {
        initNewGame();
        return headers + getMazeJson();
    }
    
    if (request.find("POST /move") != string::npos) {
        if (!game.gameActive) {
            return headers + getMazeJson();
        }
        
        // Extract move from request
        size_t bodyPos = request.find("\r\n\r\n");
        if (bodyPos != string::npos) {
            string body = request.substr(bodyPos + 4);
            size_t movePos = body.find("\"move\":\"");
            if (movePos != string::npos && movePos + 8 < body.length()) {
                char move = body[movePos + 8];
                cout << "Move: " << move << endl;
                
                int newX = game.playerX, newY = game.playerY;
                
                switch (move) {
                    case 'w': case 'W': newX--; break;
                    case 'a': case 'A': newY--; break;
                    case 's': case 'S': newX++; break;
                    case 'd': case 'D': newY++; break;
                    case 'q': case 'Q': 
                        game.gameActive = false;
                        return headers + getMazeJson();
                }
                
                // Check if move is valid
                if (newX >= 0 && newX < HEIGHT && newY >= 0 && newY < WIDTH) {
                    if (game.maze[newX][newY] == ' ' || 
                        (newX == game.exitX && newY == game.exitY)) {
                        
                        game.playerX = newX;
                        game.playerY = newY;
                        
                        // Check win condition
                        if (game.playerX == game.exitX && game.playerY == game.exitY) {
                            game.gameActive = false;
                            cout << "Player won!" << endl;
                            return headers + getMazeJson();
                        }
                        
                        // Move bots
                        moveBots();
                        
                        // Check if either bot caught player
                        if ((game.bot1X == game.playerX && game.bot1Y == game.playerY) ||
                            (game.bot2X == game.playerX && game.bot2Y == game.playerY)) {
                            game.gameActive = false;
                            cout << "A bot caught the player!" << endl;
                        }
                    }
                }
            }
        }
        
        return headers + getMazeJson();
    }
    
    if (request.find("GET /state") != string::npos) {
        return headers + getMazeJson();
    }
    
    return "HTTP/1.1 404 Not Found\r\n\r\n";
}

int main() {
    srand(time(0));
    
#ifdef _WIN32
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
#endif

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;
    setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));
    
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    
    if (bind(serverSocket, (sockaddr*)&address, sizeof(address)) < 0) {
        cout << "Bind failed!" << endl;
        return 1;
    }
    
    listen(serverSocket, 3);
    cout << "🚀 Maze server running on http://localhost:8080" << endl;
    cout << "Debug mode: ON" << endl;
    
    while (true) {
        sockaddr_in clientAddr{};
        socklen_t clientLen = sizeof(clientAddr);
        int clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientLen);
        
        if (clientSocket >= 0) {
            char buffer[4096] = {};
            int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
            
            if (bytesRead > 0) {
                string request(buffer, bytesRead);
                string response = handleRequest(request);
                send(clientSocket, response.c_str(), response.length(), 0);
            }
            
#ifdef _WIN32
            closesocket(clientSocket);
#else
            close(clientSocket);
#endif
        }
    }
    
    return 0;
}
