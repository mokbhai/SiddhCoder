# Types of Data Types in Cpp
## 1. Primitive Data Type
###    a. Integers
    Range -> -1294967296 to +1294967295.
    sizeof(int) -> 4 bytes.
    1. Signed Integer -> Always Positive.
    2. Unsigned Integer -> Can be both positive and negative.

###    b. Characters
    Range -> -128 to +127.
    sizeof(char) -> 1 bytes.

###    c. Boolean
    sizeof(bool) -> 1 bytes.
    Takes:
        0 | false
        1 | true
        All values except 0 are true.
    
###    d. Float Numbers
    Non-real numbers, Decimal points (eg 2.83).
    Stores up to 6 decimal places.
    sizeof(float) -> 4 bytes.

###    e. Double Numbers

###    f. Void

###    g. Wide Characters (wchar_t)
    sizeof(wchar_t) -> 2 bytes
    Used as:
        ~ wchar_t str[] = L"Hello, world!";
        ~ wchar_t c = L'a';

### DataType Modifiers
    1. Signed: can store both positive and negative integers.
    2. Unsigned: can only store positive integers.
    3. Long: increases the size of the data type.
    4. Short: decreases the size of the data type.
    5. Double: stores floating-point numbers with more precision than float.

## 2. Derived Data Type

## 3. User Defined Data Types
