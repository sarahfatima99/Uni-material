#include<iostream>
#include<queue>
using namespace std;

void pArray(int arr[],int n);

void bubbleSort(int *arr,int n){
	for(int i =0;i<n-1;i++){
		for(int j =0;j<n-i-1;j++){
			cout<<"Current Index is "<<i<<"\n";
			if(arr[j]>arr[j+1]){
				cout<<arr[j]<<" Swapped with "<<arr[j+1]<<"\n";
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		cout<<"\n Current array\n";
		pArray(arr,n);
	}
}
//bubble end

void pArray(int *arr,int n){
		for(int i =0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n\n";
}


void insertionSort(int a[],int n){
	int i,j;
	for(i =1;i<n;i++){
		cout<<"Current iteration is "<<i<<"\n";
		j=i-1;
		int temp = a[i];
		while(i>0 && a[j] > temp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = temp;
		pArray(a,n);
	}
}

//insertion end

void selectionSort(int a[],int n){
	for(int i =0;i<n;i++){
		int min =i;
		cout<<"Current Index is "<<i<<"\n\n";
		for(int j = i;j<n;j++){
			if(a[min] > a[j])
				min =j;
		}
		if(a[min] != a[i]){
			
			cout<<a[i]<<" Swapped with "<<a[min]<<"\n";
			int temp = a[min];
			a[min] = a[i];
			a[i] = temp;
		}
		else{
			cout<<a[i]<<" is already at correct position "<<"\n";
		}
		pArray(a,n);
	}
}


//selection end


void cocktailSort(int arr[],int n){
	for(int i =0;i<n-1;i++){
			cout<<"Current Index is "<<i<<"\n";
		for(int j =0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				cout<<arr[j]<<" Swapped with "<<arr[j+1]<<"\n";
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		for(int j =n-i-2;j>=0;j--){
			if(arr[j]<arr[j-1]){
				cout<<arr[j]<<" Swapped with "<<arr[j-1]<<"\n";
				int temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
		cout<<"\n Current array\n";
		pArray(arr,n);
	}
}

//cocktail end


void MergeTwo(int a[],int low,int high,int mid)
{
	int i=low;
	int j=mid+1;
	int k=0;
	int temp[high-low+1];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		{
			temp[k]=a[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=a[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		k++;
		i++;
	}
	while(j<=high)
	{
		temp[k]=a[j];
		k++;
		j++;
	}
	for(i=low;i<=high;i++)
	{
		a[i]=temp[i-low];
	}
}
void MergeSort(int a[],int low,int high)
{
	if(low<high)
	{	
		int mid=(high+low)/2;
		MergeSort(a,low,mid);
		MergeSort(a,mid+1,high);
		MergeTwo(a,low,high,mid);
	}
	return;
}

//merge end

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  


int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];
    int i = (low - 1);   
  
    for (int j = low; j <= high - 1; j++)  
    {   
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  


void quickSort(int a[],int low,int high,int i=0){
	 
	if (low < high)  
    {  
    	 
        int pi = partition(a, low, high);  
        quickSort(a, low, pi - 1,i+1);  
        quickSort(a, pi + 1, high,i+1);  
        cout<<"Current Iteration is "<<i<<"\n";
        pArray(a,high-low+1);
       
    }  
}

//quick end


void radixSort(int Data[],int n){
	const int radix = 10;
	const int digits = 1;//<- Number of digits possible like 100 has 3
	queue<int>Q[radix];
	for(int d =0 ,fact =1;d<digits;fact += radix,d++){
		cout<<"Current D index :"<<d<<"\n\n\n";
		for(int j=0;j<n;j++){
			Q[(Data[j]/fact) % radix].push(Data[j]);
		}
		for(int k = 0,j=0;j<radix;j++){
			while(!(Q[j].empty())){
				Data[k++] = Q[j].front();
				Q[j].pop();
			}
		cout<<"Current J index :"<<j<<"\n";
		pArray(Data,9);
		cout<<"\n";
		}
	}
}

//radix end

int getLargest(int a[],int n){
	int largest = a[0];
	for(int i=1;i<n;i++){
		if(largest < a[i]){
			largest = a[i];
		}
	} 
	return largest;
}


void countSort(int arr[],int n){
	int largest;
	largest = getLargest(arr,n);
	int count[largest+1];
	for(int i=0;i<=largest;i++){
		count[i]=0;
	}
	 int temp[n];
	for(int i=0;i<n;i++)
		temp[i]=0;
	for(int i = 0; arr[i]; ++i)  
        ++count[arr[i]];
    	cout<<"Seprate Count array \n\n";
    	pArray(count,largest+1);
    for (int i = 1; i <= largest; ++i)  
        count[i] += count[i-1];
        cout<<"Joint Count array \n\n";
    	pArray(count,largest+1);
    for (int i = 0; arr[i]; ++i)  
    {  
        temp[count[arr[i]]-1] = arr[i];  
        --count[arr[i]];  
    }  
    for(int i=0;temp[i];i++){
    	arr[i] = temp[i];
	}
    cout<<"Final Array\n";
	pArray(arr,n);
}


//count end

int getNextGap(int gap) 
{ 
    gap = (gap*10)/13; 
  
    if (gap < 1) 
        return 1; 
    return gap; 
} 

void combSort(int a[], int n) 
{ 
     
    int gap = n;  
    bool swapped = true; 
    while (gap != 1 || swapped == true) 
    { 
        gap = getNextGap(gap); 
        cout<<"\nCurrent Gap "<<gap<<"\n\n";
        swapped = false; 
        for (int i=0; i<n-gap; i++) 
        { 
            if (a[i] > a[i+gap]) 
            { 
            	cout<<a[i]<<" Swapped with "<<a[i+gap]<<"\n";
                swap(a[i], a[i+gap]); 
                swapped = true; 
            }
        }
        
        cout<<"\nCurrent array\n\n";
		pArray(a,n);
    }
} 

//comb end

int main(){
	int arr[9]={9,8,7,6,5,4,3,2,1};
	pArray(arr,9);
	//bubbleSort(arr,9);
	//insertionSort(arr,9);
	//selectionSort(arr,9);
	//cocktailSort(arr,9);
	//MergeSort(arr,0,8);pArray(arr,9); cout<<"\nCan't Help in Recursion \n";
	//quickSort(arr,0,8);
	//radixSort(arr,9);
	//countSort(arr,9);
	//combSort(arr,9);
	return 0;
}

