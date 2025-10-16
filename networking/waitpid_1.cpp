#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
int main (){
    pid_t pid=fork();
    if (pid==-1){
        perror("fork");
        return 1;
    }
    else if (pid==0){
        std::cout << "Child : Pid " << getpid() << "started and will sleep for 5 seconds\n";
        sleep(5);
        std::cout << "child : exits\n";
        _exit(0);
    }
    else {
        std::cout << "parent is here with child with a pid " << pid << "\n";
        std::cout << "blocking :: ";
        int status;
        std::cout << "parent waiting untill child is block \n";
        waitpid(pid,&status,0);
        std::cout << "parent's child exiited with status code : " << WEXITSTATUS(status) << "\n";
        std::cout << "\n non blocking mode \n";
        pid_t child2=fork();
        if (child2==0){
            std::cout << "child2:pid " << getpid() << "started sleeping for 5 seconds\n";
            sleep(5);
            std::cout << "child2: exiting now!\n";
            _exit(0);
        }
        else {
        int status2;
            for (int i=0;i<5;i++){
                pid_t result=waitpid(child2,&status2,WNOHANG);
                if (result==0){
                    std::cout << "Parent : chidl2 still running ...(loop "<<i << ")\n";
                    sleep(1);
                }
                else if (result==child2){
                    std::cout << "Parent : child2 exited ! status =" << WEXITSTATUS(status2)<<"\n";
                    break;
                }
                else {
                    perror("waitpid");
                    break;
                }
            }
        }
    }
    return 0;
}

