void sigchld handler(int s){
    (void)s;
    int saved_errno=errno;
    while(waitpid(-1,NULL,WNOHANG)>0);
    errno=saved_errno;
}

sa.sa_handler_=sigchld_handler;
sigempty(&sa.sa_mask);
sa.sa_flags=SA_RESTART;
if (sigaction(SIGCHLD,&sa,NULL)==-1){
    perror("sigaction");
    exit(1);
}
