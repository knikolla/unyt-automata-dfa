#include "utilities.h"

#include <vector>
#include <string>

std::vector<std::string> utilities::split(const  std::string &theString, const std::string &delimiter)
{
    std::vector<std::string> result;
    
    size_t  start = 0, end = 0;
    
    while ( end != std::string::npos)
    {
        end = theString.find( delimiter, start);
        
        result.push_back( theString.substr( start,
                                           (end == std::string::npos) ? std::string::npos : end - start));
        
        start = (   ( end > (std::string::npos - delimiter.size()) )
                 ?  std::string::npos  :  end + delimiter.size());
    }
    
    return result;
}
