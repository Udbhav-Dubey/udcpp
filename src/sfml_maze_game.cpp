#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <random>
#include <chrono>
using namespace std::chrono;
using namespace std;

const int MAZE_WIDTH = 21;
const int MAZE_HEIGHT = 21;
const int CELL_SIZE = 25;  // Size of each maze cell in pixels
const int WINDOW_WIDTH = MAZE_WIDTH * CELL_SIZE + 200;  // Extra space for UI
const int WINDOW_HEIGHT = MAZE_HEIGHT * CELL_SIZE + 100;

class MazeGame {
private:
    sf::RenderWindow window;
    sf::Font font;
    vector<vector<char>> maze;
    int playerX, playerY;
    int exitX, exitY;
    steady_clock::time_point startTime;
    const int timeLimit = 120; // 2 minutes
    bool gameWon;
    bool gameLost;
    
    // Colors
    sf::Color wallColor = sf::Color::Black;
    sf::Color pathColor = sf::Color::White;
    sf::Color playerColor = sf::Color::Blue;
    sf::Color exitColor = sf::Color::Green;

public:
    MazeGame() : window(sf::VideoMode(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT)), "Maze Game"),
                 maze(MAZE_HEIGHT, vector<char>(MAZE_WIDTH, '|')),
                 playerX(1), playerY(1), gameWon(false), gameLost(false) {
        
        // Try to load a font (you might need to provide a font file)
        if (!font.openFromFile("/System/Library/Fonts/Arial.ttf")) {
            // If system font doesn't work, try these common paths
            if (!font.openFromFile("arial.ttf") && 
                !font.openFromFile("C:/Windows/Fonts/arial.ttf") &&
                !font.openFromFile("/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf")) {
                // Use default font if no custom font is available
                // SFML will use a built-in font
            }
        }
        
        generateMaze();
        createExit();
        maze[playerX][playerY] = 'P';
        startTime = steady_clock::now();
    }

    void generateMaze() {
        carveMaze(1, 1);
    }

    void carveMaze(int x, int y) {
        maze[x][y] = ' ';
        
        const vector<pair<int,int>> directions = {
            {-2, 0}, // North
            {2, 0},  // South
            {0, 2},  // East
            {0, -2}  // West
        };
        
        vector<pair<int,int>> dirs = directions;
        random_device rd;
        mt19937 g(rd());
        shuffle(dirs.begin(), dirs.end(), g);
        
        for (auto [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            
            if (isValid(nx, ny) && maze[nx][ny] == '|') {
                maze[x + dx/2][y + dy/2] = ' ';
                carveMaze(nx, ny);
            }
        }
    }

    bool isValid(int x, int y) {
        return x > 0 && x < MAZE_HEIGHT - 1 && y > 0 && y < MAZE_WIDTH - 1;
    }

    void createExit() {
        vector<pair<int,int>> possibleExits;
        
        // Check top and bottom edges
        for (int i = 1; i < MAZE_WIDTH - 1; ++i) {
            if (maze[1][i] == ' ') possibleExits.emplace_back(0, i);
            if (maze[MAZE_HEIGHT-2][i] == ' ') possibleExits.emplace_back(MAZE_HEIGHT-1, i);
        }
        
        // Check left and right edges
        for (int i = 1; i < MAZE_HEIGHT - 1; ++i) {
            if (maze[i][1] == ' ') possibleExits.emplace_back(i, 0);
            if (maze[i][MAZE_WIDTH-2] == ' ') possibleExits.emplace_back(i, MAZE_WIDTH-1);
        }
        
        if (!possibleExits.empty()) {
            random_device rd;
            mt19937 g(rd());
            uniform_int_distribution<> dis(0, possibleExits.size() - 1);
            auto [ex, ey] = possibleExits[dis(g)];
            exitX = ex;
            exitY = ey;
            maze[exitX][exitY] = 'E';
        }
    }

    void handleInput() {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            
            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (!gameWon && !gameLost) {
                    int newX = playerX;
                    int newY = playerY;
                    
                    switch (keyPressed->code) {
                        case sf::Keyboard::Key::W:
                        case sf::Keyboard::Key::Up:
                            newX--;
                            break;
                        case sf::Keyboard::Key::S:
                        case sf::Keyboard::Key::Down:
                            newX++;
                            break;
                        case sf::Keyboard::Key::A:
                        case sf::Keyboard::Key::Left:
                            newY--;
                            break;
                        case sf::Keyboard::Key::D:
                        case sf::Keyboard::Key::Right:
                            newY++;
                            break;
                        case sf::Keyboard::Key::Q:
                        case sf::Keyboard::Key::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::Key::R:
                            if (gameWon || gameLost) {
                                restartGame();
                            }
                            break;
                        default:
                            break;
                    }
                    
                    // Check if move is valid
                    if (newX >= 0 && newX < MAZE_HEIGHT && newY >= 0 && newY < MAZE_WIDTH &&
                        (maze[newX][newY] == ' ' || maze[newX][newY] == 'E')) {
                        
                        maze[playerX][playerY] = ' '; // Clear old position
                        playerX = newX;
                        playerY = newY;
                        maze[playerX][playerY] = 'P';
                        
                        // Check win condition
                        if (playerX == exitX && playerY == exitY) {
                            gameWon = true;
                        }
                    }
                }
                
                if (gameWon || gameLost) {
                    if (keyPressed->code == sf::Keyboard::Key::R) {
                        restartGame();
                    }
                }
            }
        }
    }

    void restartGame() {
        // Reset maze
        maze = vector<vector<char>>(MAZE_HEIGHT, vector<char>(MAZE_WIDTH, '|'));
        playerX = 1;
        playerY = 1;
        gameWon = false;
        gameLost = false;
        
        generateMaze();
        createExit();
        maze[playerX][playerY] = 'P';
        startTime = steady_clock::now();
    }

    void update() {
        if (!gameWon && !gameLost) {
            auto currentTime = steady_clock::now();
            int elapsed = duration_cast<seconds>(currentTime - startTime).count();
            if (elapsed >= timeLimit) {
                gameLost = true;
            }
        }
    }

    void render() {
        window.clear(sf::Color::Black);
        
        // Draw maze
        sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
        
        for (int i = 0; i < MAZE_HEIGHT; ++i) {
            for (int j = 0; j < MAZE_WIDTH; ++j) {
                cell.setPosition(sf::Vector2f(j * CELL_SIZE, i * CELL_SIZE));
                
                switch (maze[i][j]) {
                    case '|':
                        cell.setFillColor(wallColor);
                        break;
                    case ' ':
                        cell.setFillColor(pathColor);
                        break;
                    case 'P':
                        cell.setFillColor(playerColor);
                        break;
                    case 'E':
                        cell.setFillColor(exitColor);
                        break;
                }
                
                window.draw(cell);
            }
        }
        
        // Draw UI text
        sf::Text text(font, "", 20);
        text.setFillColor(sf::Color::White);
        
        // Instructions
        text.setString("Use WASD or Arrow Keys to move. Q/ESC to quit.");
        text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 10));
        window.draw(text);
        
        // Timer
        if (!gameWon && !gameLost) {
            auto currentTime = steady_clock::now();
            int elapsed = duration_cast<seconds>(currentTime - startTime).count();
            int remaining = timeLimit - elapsed;
            
            text.setString("Time: " + to_string(remaining) + "s");
            text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 40));
            if (remaining <= 10) {
                text.setFillColor(sf::Color::Red);
            } else {
                text.setFillColor(sf::Color::White);
            }
            window.draw(text);
        }
        
        // Game status
        if (gameWon) {
            text.setString("YOU WIN!");
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::Green);
            text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 80));
            window.draw(text);
            
            text.setString("Press R to restart");
            text.setCharacterSize(16);
            text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 120));
            window.draw(text);
        } else if (gameLost) {
            text.setString("TIME'S UP!");
            text.setCharacterSize(30);
            text.setFillColor(sf::Color::Red);
            text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 80));
            window.draw(text);
            
            text.setString("Press R to restart");
            text.setCharacterSize(16);
            text.setFillColor(sf::Color::White);
            text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 120));
            window.draw(text);
        }
        
        // Legend
        text.setCharacterSize(14);
        text.setFillColor(sf::Color::White);
        text.setString("Legend:");
        text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 160));
        window.draw(text);
        
        text.setFillColor(sf::Color::Blue);
        text.setString("■ Player");
        text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 180));
        window.draw(text);
        
        text.setFillColor(sf::Color::Green);
        text.setString("■ Exit");
        text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 200));
        window.draw(text);
        
        text.setFillColor(sf::Color::Black);
        text.setString("■ Wall");
        text.setPosition(sf::Vector2f(MAZE_WIDTH * CELL_SIZE + 10, 220));
        window.draw(text);
        
        window.display();
    }

    void run() {
        while (window.isOpen()) {
            handleInput();
            update();
            render();
        }
    }
};

int main() {
    MazeGame game;
    game.run();
    return 0;
}
