class StaticTest {
private:
    static int m_value;
public:
    static int getValue() { // Define static member function
        return m_value;
    }
};
int StaticTest::m_value = 12;

// Invocation methods
StaticTest t;
int val1 = t.getValue(); // Call via object
int val2 = StaticTest::getValue(); // Call via class name