#include <iostream>
#include <thread>
#include <vector>
#include <stdexcept>

void globalExceptionHandler()
{
    try
    {
        // attempt to re-throw the current exception
        std::rethrow_exception(std::current_exception());
    }
    catch (const std::exception &e)
    {
        // catch and handle the standard exception
        std::cerr << "Global Exepction Handler: Unhandled exception of typ '"
                  << typeid(e).name() << "' with message: '" << e.what() << "'" << std::endl;
    }
    catch (...)
    {
        // catch non standard exceptions
        std::cerr << "Global Exeption Hander: Unkown exception type" << std::endl;
    }

    std::abort(); // terminate the program after handling an exception.
}

void threadFunction(int id)
{
    // Simulate a task that might throw an exception
    if (id % 2 == 0)
    { // Threads with even IDs throw an exception
        throw std::runtime_error("Exception from thread " + std::to_string(id));
    }
}

int main()
{
    std::set_terminate(globalExceptionHandler);

    const int numThreads = 4;
    std::vector<std::thread> threads;

    // Spawn threads
    for (int i = 0; i < numThreads; ++i)
    {
        threads.emplace_back(threadFunction, i);
    }

    // Join threads
    for (auto &th : threads)
    {
        th.join();
    }

    std::cout << "All threads have completed." << std::endl;

    return 0;
}