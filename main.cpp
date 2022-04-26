#include <iostream>

void mergeSort(int array[], int sizeOfArray)
{
    for(int size{1}; (size * 2) <= (sizeOfArray + size); size *= 2)
    {
        std::cout << size << std::endl;

        for(int firstP{0}, secondP{size}; secondP < sizeOfArray; firstP += (size * 2), secondP += (size * 2))
        {
            int secondPartSize{ secondP + size > sizeOfArray ? sizeOfArray - secondP : size };
            int tempArraySize = size + secondPartSize;
            int *tempArray{ new int[tempArraySize] };

            std::cout << firstP << " " << secondP << " " << secondPartSize << std::endl;

            for(int i{0}, firstPit{ firstP }, secondPIt{ secondP }; i < tempArraySize; i++) {
                auto addTo{
                        [&tempArray, &array, i](int &it)
                        {
                            tempArray[i] = array[it];
                            it++;
                        }};

                if(firstPit < firstP + size && secondPIt < secondP + secondPartSize)
                {
                    if(array[firstPit] < array[secondPIt])
                    {
                        addTo(firstPit);
                    }
                    else
                    {
                        addTo(secondPIt);
                    }
                }
                else if(firstPit < firstP + size)
                {
                    addTo(firstPit);
                }
                else
                {
                    addTo(secondPIt);
                }
            }

            for(int i{0}, arrayIt{ firstP }; i < tempArraySize; i++, arrayIt++)
            {
                array[arrayIt] = tempArray[i];
            }

            delete[] tempArray;
        }

        std::cout << std::endl;
    }
}

int main()
{
    int array[] = {8, 2, 17, 15, 1, 3, 14, 4, 16, 6, 5, 10, 11, 12, 13, 9, 7};

    int size = sizeof(array) / sizeof(array[0]);

    mergeSort(array, size);

    for(int i{0}; i < size; ++i)
    {
        std::cout << i + 1 << " " << array[i] << std::endl;
    }

    return 0;
}
