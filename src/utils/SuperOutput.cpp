#include "SuperOutput.h"
#include <iostream>

SuperOutput::SuperOutput(std::string filename)
{
    this->file.open(filename);
}

void SuperOutput::print(std::string input)
{
    std::cout << input;
    this->file << input;
}

void SuperOutput::println()
{
    std::cout << "\n";
    this->file << "\n";
}

void SuperOutput::println(std::string input)
{
    std::cout << std::endl << input;
    this->file << std::endl << input;
}

void SuperOutput::printFile(std::string input)
{
    this->file << input;
}

void SuperOutput::printlnFile()
{
    this->file << std::endl;
}

void SuperOutput::printlnFile(std::string input)
{
    this->file << std::endl << input;
}

void SuperOutput::close()
{
    this->file.close();
}