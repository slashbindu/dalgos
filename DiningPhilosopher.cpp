#include<mutex>
#include<condition_variable>

using namespace std;


class DiningPhilosophers {
public:
    
    array<mutex, 5> fork_locks;
    mutex seat;
    int seats;
    int nph;
    condition_variable cv_can_sit;
    
      
    DiningPhilosophers() {
         
        nph = 5;
        seats = nph-1;
     }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        
        
            {
                unique_lock<mutex> slock(seat);
                cv_can_sit.wait(slock, [this](){ return seats > 0; });
                seats--;
            }

            cout << "#" << philosopher  << "  seated " << endl;
            fork_locks[philosopher% nph].lock();
            fork_locks[philosopher+1% nph].lock();
            cout << "#" << philosopher << "  eating " << endl;
            pickLeftFork();
            pickRightFork();
            eat();
              
            fork_locks[philosopher].unlock();
            fork_locks[philosopher+1%nph].unlock();
            cout << "#" << philosopher <<  "  done " << endl;
        
            {
                unique_lock<mutex> slock(seat);
                seats++;
                cv_can_sit.notify_one();
            }
            cout << "#" << philosopher  << "  left" <<  endl;
            putLeftFork();
            putRightFork();
           }
        
           
};
