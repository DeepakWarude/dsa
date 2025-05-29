#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// Function to input student marks
void inputData(vector<int> &marks, int n)
{
    marks.clear();
    for(int i = 0; i < n; i++)
    {
        int x;
        cout << "Enter the Marks of Student " << i + 1 << " : ";
        cin >> x;
        marks.push_back(x);
    }
}

// Function to display marks
void display(const vector<int> &arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


// Bubble Sort
void BubbleSort(vector<int> &arr)
{
    int n = arr.size();

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort
void SelectionSort(vector<int> &arr)
{
    int n = arr.size();

    for(int i = 0; i < n; i++)
    {
        int min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// Insertion Sort
void InsertionSort(vector<int> &arr)
{
    int n = arr.size();
    int temp;
    int j;

    for(int i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i;
        while(j > 0 && arr[j - 1] > temp)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}

// Merge Sort
void merge(vector<int> &arr,int low,int mid,int high)
{
    vector<int> temp;
    int left=low;
    int right = mid+1;
    
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }

       
    }
    while(left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void ms(vector<int> &arr,int low,int high)
{
    if(low==high) return;

    int mid = (low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void MergeSort(vector<int> &arr,int n)
{
    ms(arr,0,n-1);
}

// Shell Sort
void ShellSort(vector<int> &arr)
{
    int n = arr.size();

    for (int gap=n/2;gap>0;gap/=2)
    {
        for (int i=gap;i<n;i++)
        {
            int temp=arr[i];
            int j;
            for (j=i; j>=gap && arr[j-gap]>temp;j-=gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j]=temp;
        }
    }
}


//Quick Sort
int partition(vector<int> &arr,int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;

    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }
        
        while(arr[j]>=pivot && j>=low+1)
        {
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int pIndex=partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}

vector<int> QuickSort(vector<int>arr)
{
    qs(arr,0,arr.size()-1);
    return arr;
}
//Radix Sort
void RadixSort(vector<int> &arr) 
{
    vector<int> temp;
    for (int x : arr) temp.push_back(int(x * 100));

    int maxVal = *max_element(temp.begin(), temp.end());

    for (int exp = 1; maxVal / exp > 0; exp *= 10) 
    {
        vector<int> output(temp.size());
        int count[10] = {0};

        for (int i = 0; i < temp.size(); i++)
            count[(temp[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = temp.size() - 1; i >= 0; i--) 
        {
            output[count[(temp[i] / exp) % 10] - 1] = temp[i];
            count[(temp[i] / exp) % 10]--;
        }
        temp = output;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = temp[i] / 100.0;
}

// Display top 5 scores
void displayTop5(const vector<int> &arr)
{
    int count = min(5, (int)arr.size());
    for(int i = arr.size() - count; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    vector<int> marks;
    int n, choice;

    cout << "Enter the Number of Students: ";
    cin >> n;

    inputData(marks, n);

    do
    {
        cout << "\n===== Menu =====\n";
        cout << "1. Selection Sort\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Merge Sort\n";
        cout << "5. Shell Sort\n";
        cout << "6. Quick Sort\n";
        cout << "7. Radix Sort\n";
        cout << "8. Display Top 5 Students' Marks\n";
        cout << "0. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        vector<int>sorted = marks;  // Copy original marks to sort

        switch (choice)
        {
            case 1:
                SelectionSort(sorted);
                cout << "Sorted marks using Selection Sort : ";
                display(sorted);
                break;

            case 2:
                BubbleSort(sorted);
                cout << "Sorted marks using Bubble Sort : ";
                display(sorted);
                break;

            case 3:
                InsertionSort(sorted);
                cout << "Sorted marks using Insertion Sort :";
                display(sorted);
                break;
            
            case 4:
                MergeSort(sorted,n);
                cout << "Sorted marks using Merge Sort :";
                display(sorted);
                break;

            case 5:
                ShellSort(sorted);
                cout << "Sorted marks using Shell Sort :";
                display(sorted);
                break;
            
            case 6:
                sorted=QuickSort(sorted);
                cout << "Sorted marks using Quick Sort :";
                display(sorted);
                break;

            case 7:
                RadixSort(sorted);
                cout << "Sorted marks using Radix Sort :";
                display(sorted);
                break;

            case 8:
                sort(sorted.begin(), sorted.end());
                cout << "Top 5 scores: ";
                displayTop5(sorted);
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option!\n";
                break;
        }
    }
    while (choice != 0);

    return 0;
}
