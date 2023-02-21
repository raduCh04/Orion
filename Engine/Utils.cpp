#include "Utils.h"

namespace Orion
{
    std::string read_file(const std::string& source)
    {
        FILE* file = fopen(source.c_str(), "rt");
        fseek(file, 0, SEEK_END);
        uint64_t length = ftell(file);
        char* data = (char*)malloc(length + 1);
        memset(data, 0, length + 1);
        fseek(file, 0, SEEK_SET);
        fread(data, 1, length, file);
        fclose(file);

        std::string result(data);
        free(data);
        return (result);
    }
} // namespace Orion