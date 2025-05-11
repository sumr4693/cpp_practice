
template <typename T>
void util::heap::min_heapify(std::vector<T>& elements, int n, int index)
{
    int smallest = -1;

    while (smallest != index)
    {
        if (smallest != -1)
        {
            std::swap(elements[smallest], elements[index]);
            index = smallest;
        }
        
        smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
    
        if (left < n && elements[left] < elements[smallest])
        {
            smallest = left;
        }
    
        if (right < n && elements[right] < elements[smallest])
        {
            smallest = right;
        }
    }
}

template <typename T>
void util::heap::max_heapify(std::vector<T>& elements, int n, int index)
{
    int largest = -1;

    while (largest != index)
    {
        if (largest != -1)
        {
            std::swap(elements[largest], elements[index]);
            index = largest;
        }
        
        largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
    
        if (left < n && elements[left] > elements[largest])
        {
            largest = left;
        }
    
        if (right < n && elements[right] > elements[largest])
        {
            largest = right;
        }
    }
}