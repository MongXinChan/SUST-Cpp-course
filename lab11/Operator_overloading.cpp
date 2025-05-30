// Simplified String class
class String {
private:
    char* m_data;
    // ... other members like size, capacity ...
public:
    // ... constructors, destructor, etc. ...

    char& operator[](std::size_t position) {
        // Add bounds checking if necessary
        return m_data[position];
    }

    const char& operator[](std::size_t position) const {
        // Add bounds checking if necessary
        return m_data[position];
    }
    // ...
};
