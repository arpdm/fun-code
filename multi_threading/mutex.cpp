#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex guard;
std::condition_variable cv;

int counter{0};
int cycle{0};

void thread_handler(int thread_ref)
{
    std::unique_lock<std::mutex> lock(guard);
    std::cout << "Thread " << thread_ref << " Cycle " << cycle << std::endl;
    cycle++;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    lock.unlock();
}


int main()
{
    const int num_threads = 4;
    std::thread thread_pool[num_threads];

    for(int i = 0; i < num_threads; i++) {
        thread_pool[i] = std::thread(thread_handler, i);
    }

    for (int i = 0; i < num_threads; i++) {
        thread_pool[i].join();
    }

    return 0;
}
