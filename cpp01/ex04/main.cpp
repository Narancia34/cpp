/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nara <nara@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:17:23 by mgamraou          #+#    #+#             */
/*   Updated: 2025/11/03 17:25:01 by nara             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replaceLine(const std::string &line, const std::string &s1, const std::string &s2){
    if (s1.empty())
        return line;
    std::string result = line;
    size_t pos = 0;
    while (pos = result.find(s1, pos), pos != std::string::npos){
        result.erase(pos, s1.length());
        result.insert(pos, s2);
        pos += s2.length();
    }
    return result;
}

int main (int argc, char **argv){
if (argc != 4){
    std::cerr << "Usage: " << argv[0] << "<filename> <string1> <string2>" << std::endl;
    return 1;
}
std::string filename = argv[1];
std::string s1 = argv[2];
std::string s2 = argv[3];

std::ifstream inputFile(filename.c_str());
if (!inputFile.is_open()){
    std::cerr << "Error: Could not open file " << filename << std::endl;
    return 1;
}

std::string outputFilename = filename + ".replace";
std::ofstream outputFile(outputFilename.c_str());
if (!outputFile.is_open()){
    std::cerr << "Error: Could not create file " << outputFilename << std::endl;
    inputFile.close();
    return 1;
}

std::string line;
bool firstLine = true;
while(std::getline(inputFile, line)){
    if (!firstLine)
        outputFile << "\n";
    outputFile << replaceLine(line, s1, s2);
    firstLine = false;
}
inputFile.close();
outputFile.close();
std::cout << "File processed successfully. Output written to " << outputFilename << std::endl;
return 0;
}