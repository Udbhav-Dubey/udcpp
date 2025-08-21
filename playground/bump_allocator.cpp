#include <iostream>
#include <cstdint>
class BumpAllocator{
private:
    char*m_buffer;
    size_t m_buffer_size;
    size_t m_offset;
public :
    BumpAllocator(size_t buffer_size):
        m_buffer_size(buffer_size),m_offset(0){
            m_buffer=new (std::nothrow) char[m_buffer_size];
            if (!m_buffer){
                std::cerr<< "Failed to allocate memory for the buffer." << std::endl;
            }
        }
    ~BumpAllocator(){
        delete[] m_buffer;
    }
    void allocate(size_t size){
        if (!m_buffer){
            return nullptr;
        }
        size_t aligned offset=(m_offset+7)&~7;
        if (aligned_offset+size>m_buffer_size){
            std::cerr<<"Error : out of memory in bump allocator." << std::endl;
            return nullptr;
        }
        void *result=m_buffer+aligned_offset;
        m_offset=aligned_offset+size;
        return result;
    }
};

