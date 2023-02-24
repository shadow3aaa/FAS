#pragma once

#include <vector>
#include <sys/stat.h>
#include <fstream>

using std::ios;
using std::ofstream;
using std::vector;

// Edit and Lock a file
template <typename T>
static bool Lockvalue(const char *location, T value)
{
    chmod(location, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IWOTH | S_IROTH);
    ofstream fd(location, ios::out | ios::trunc);
    if (!fd)
        return false;
    fd << value;
    chmod(location, S_IRUSR | S_IRGRP | S_IROTH);
    return true;
}

class Cpufreq
{
    vector<unsigned long> middle_cpu_table;
    vector<unsigned long> big_cpu_table;
    int kpi;
    int kpi_min;
    short scaling;
    void getFreq();
    void Cpu_big_limit();
    void Cpu_middle_limit();

public:
    Cpufreq();
    Cpufreq(const Cpufreq &other) = delete; // dont copy this
    void show_middle_table();
    void show_big_table();
    void limit(const int &n);
    void limit_clear();
    void set_scaling(const short &n);
};
