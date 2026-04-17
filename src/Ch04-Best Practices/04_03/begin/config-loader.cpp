#include <iostream>
#include <stdexcept>
#include <memory>

class ConfigLoader
{
private:
    std::string configuration;
    std::unique_ptr<int[]> settingsBuffer;

public:
    ConfigLoader(const std::string &configName) : configuration(configName), settingsBuffer(std::make_unique<int[]>(1024))

    {
        // Simulate allocation for settings
        std::cout << "Constructing loader for config: " << configName << ".\n";

        if (configName == "invalid")
        {
            std::cout << "In ConfigLoader ctor, about to throw an exception due to invalid configuration" << std::endl;
            throw std::runtime_error("Failed to load configuration: " + configName);
        }
    }
    /* no longer needed after usage of unique_ptr
    ~ConfigLoader()
    {
        std::cout << "Releasing settings buffer for config: " << configuration << ".\n";
        delete[] settingsBuffer;
    }
    */
};

void simulateConfigLoading()
{
    try
    {
        ConfigLoader validLoader("default");
        ConfigLoader invalidLoader("invalid");
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
}

int main()
{
    simulateConfigLoading();
    return 0;
}