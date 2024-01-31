void philosopher(int i)
{
    while (true)
    {
        think(i);
        take_fork(i);
        take_fork((i + 1) % N);
        eat();
        put_fork(i);
        put_fork((i + 1) % N);
    }
}
/*--------Obvious Solution---------*/

semaphore fork [5];
int i;
void philosopher(int i)
{
    while (true)
    {
        think();
        wait(fork[i]);
        wait(fork[i+1 % 5]);
        eat();
        signal(fork[i]);
        signal(fork[i+1 % 5]);
    }
}

/*---------Proper Sempahore Solution---------*/

#define N 5
#define LEFT (i+N-1)%N
#define RIGHT (i+1)%N
#define THINKING 0
#define HUNGRY 1
#define EATING 2

typedef int semaphore;
semaphore mutex = 1;
sempahore state[N]
sempahore s[N];

void philosopher(int i){
    while(True){
        think();
        take_forks(i);
        eat();
        put_forks(i);
    }
}

void take_forks(i){
    down (&mutex);
    state[i] = HUNGRY;
    test(i);
    up(&mutex);
    down(&s[i]);
}

void test(i){
    if (state[LEFT] != EATING && state[RIGHT] != EATING && state[i] == HUNGRY){
        state[i] = EATING;
        up(&s[i]);
    }
}

void put_forks(i){
    down(&mutex);
    state[i] = THINKING
    test(LEFT);
    test(RIGHT);
    up(&mutex);
}


/*-------------Monitor-------------*/


monitor DiningPhilosopher{
    enum {THINKING, HUNGRY, EATING} states[5];
    condition self[5];

    void pickup(int i){
        state[i] = HUNGRY;
        test(i);
        if (state[i] != EATING){
            self[i].wait();
        }
    }

    void test(int i){
        if (state[i+1 % N] != EATING && state[i+N-1 % N] != EATING && state[i] == HUNGRY){
            state[i] = EATING;
            self[i].signal();
        }
    }

    void putdown(int i){
        state[i] = THINKING;
        test(i+1 % N);
        test(i+N-1 % N);
    }

    void initialization(){
        for (int i = 0; i < N; i++){
            state[i] = THINKING;
        }
    }
    
}