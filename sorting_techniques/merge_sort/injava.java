public static void mergesort(int[] arr, int low, int mid, int high) {
  int[] temp = new int[high-low+1];

  int i = low;
  int j = mid+1;
  int k = 0;
  
  while(i<=mid && j<=high){
    if (arr[i]<=arr[j]){
      temp[k++] = arr[i++];
    }else{
      temp[k++] = arr[j++];
    }
  }

  while(i<=mid){
    temp[k++] = arr[i++];
  }
  while(j<=high){
    temp[k++] = arr[j++];
  }

  for(int x = 0;x<temp.length;x++){
    arr[low+x] = temp[x];
  }
}

public static void merge(int[] arr,int left, int right){
  if (left>=right){
    return ;
  }
  int mid = left+(right-left)/2;
  merge(arr,left,mid);
  merge(arr,mid+1,right);
  mergesort(arr,left,mid,right);
}
public static void main() {
  int[] arr = { 5, 2, 4, 6, 1, 3 };
  System.out.println("Hello world");
  merge(arr,0,5);
  for (int x:arr){
    System.out.print(x+" ");
  }
}
