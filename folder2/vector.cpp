//Содержимое файла в контейнер
    std::ifstream file ("1.txt");
    std::string line;
    std::vector<std::string> mass;
 
    while (std::getline(file, line))
    {
        mass.push_back(line);
    }
