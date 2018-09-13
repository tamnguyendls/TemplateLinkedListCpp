// Using pointer of character array pointer in cpp

int GetLength(char * str)
{
    int i = 0;
    for (i = 0; str[i] != '\0'; ++i);
    return i;
}

void TestPointerToCharArrayPointer()
{
    char* string1 = "this is a cat";
    char* string2 = "this is a dog";
    char* string3 = "this is a animal";
    count = 3;

// allocate pointer to array of pointer
    //char** ptr = (char**)malloc(sizeof(char) * count);
    char ** ptr = new char*[count];

    int strlen = GetLength(string1)+1;
// allocate memory pointed by pointer member of array
    //ptr[0] = (char*)malloc(strlen);
    ptr[0] = new char[strlen];
    memset(ptr[0], NULL, strlen);
    memcpy(ptr[0], string1, strlen - 1);

    strlen = GetLength(string2) + 1;
    ptr[1] = (char*)malloc(strlen);
    memset(ptr[1], NULL, strlen);
    memcpy(ptr[1], string2, strlen - 1);

    strlen = GetLength(string3) + 1;
    ptr[2] = (char*)malloc(strlen);
    memset(ptr[2], NULL, strlen);
    memcpy(ptr[2], string3, strlen - 1);

// delete array:
    for (int i = 0; i < count; i++)
    {
        delete[] ptr[i];
        ptr[i] = NULL;
    }
    delete[] ptr; // this needs to be done last
    ptr = NULL;
}

int main()
{
    TestPointerToCharArrayPointer();
    return 0;
}