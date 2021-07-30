Problem Name : Maximum Sum rectangle in a 2D matrix
Topic : DP
Difficulty : Hard
EXPLANATION
The naive solution for this problem is to check every possible rectangle in given 2D array. This solution requires 4 nested loops and time complexity of this solution would be O(n^4).

Kadane’s algorithm for 1D array can be used to reduce the time complexity to O(n^3). The idea is to fix the left and right columns one by one and find the maximum sum contiguous rows for every left and right column pair. We basically find top and bottom row numbers (which have maximum sum) for every fixed left and right column pair. To find the top and bottom row numbers, calculate sun of elements in every row from left to right and store these sums in an array say temp[]. So temp[i] indicates sum of elements from left to right in row i. If we apply Kadane’s 1D algorithm on temp[], and get the maximum sum subarray of temp, this maximum sum would be the maximum possible sum with left and right as boundary columns. To get the overall maximum sum, we compare this sum with the maximum sum so far.

Time Complexity : O($$NNN$$).
#include<bits/stdc++.h>
using namespace std;

#define ROW 101
#define COL 101  
 int M[101][101];
 // Implementation of Kadane's algorithm for  
// 1D array. The function returns the maximum  
// sum and stores starting and ending indexes  
// of the maximum sum subarray at addresses  
// pointed by start and finish pointers  
// respectively.  
int n,m;
int kadane(int* arr, int* start, 
           int* finish, int n)  
{  
    // initialize sum, maxSum and  
    int sum = 0, maxSum = INT_MIN, i;  

    // Just some initial value to check 
    // for all negative values case  
    *finish = -1;  

    // local variable  
    int local_start = 0;  

    for (i = 0; i < n; ++i)  
    {  
        sum += arr[i];  
        if (sum < 0)  
        {  
            sum = 0;  
            local_start = i + 1;  
        }  
        else if (sum > maxSum)  
        {  
            maxSum = sum;  
            *start = local_start;  
            *finish = i;  
        }  
    }  

    // There is at-least one  
    // non-negative number  
    if (*finish != -1)  
        return maxSum;  

    // Special Case: When all numbers 
    // in arr[] are negative  
    maxSum = arr[0];  
    *start = *finish = 0;  

    // Find the maximum element in array  
    for (i = 1; i < n; i++)  
    {  
        if (arr[i] > maxSum)  
        {  
            maxSum = arr[i];  
            *start = *finish = i;  
        }  
    }  
    return maxSum;  
}  

// The main function that finds 
// maximum sum rectangle in M[][]  
void findMaxSum(int M[][COL])  
{  
    // Variables to store the final output  
    int maxSum = INT_MIN, finalLeft, finalRight,  
                          finalTop, finalBottom;  

    int left, right, i;  
    int temp[n], sum, start, finish;  

    // Set the left column  
    for (left = 0; left < COL; ++left)  
    {  
        // Initialize all elements of temp as 0  
        memset(temp, 0, sizeof(temp));  

        // Set the right column for the left 
        // column set by outer loop  
        for (right = left; right < m; ++right)  
        {  

            // Calculate sum between current left  
            // and right for every row 'i'  
            for (i = 0; i < n; ++i)  
                temp[i] += M[i][right];  

            // Find the maximum sum subarray in temp[].  
            // The kadane() function also sets values   
            // of start and finish. So 'sum' is sum of  
            // rectangle between (start, left) and  
            // (finish, right) which is the maximum sum  
            // with boundary columns strictly as left  
            // and right.  
            sum = kadane(temp, &start, &finish, n);  

            // Compare sum with maximum sum so far.  
            // If sum is more, then update maxSum and  
            // other output values  
            if (sum > maxSum)  
            {  
                maxSum = sum;  
                finalLeft = left;  
                finalRight = right;  
                finalTop = start;  
                finalBottom = finish;  
            }  
        }  
    }  

    cout<<maxSum<<endl;
}  

int main(){
        int t;
        cin>>t;
        while(t--){

            cin>>n>>m;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cin>>M[i][j];
                }
            }
            findMaxSum(M);
        }
}


Another Approach in java
import java.util.*;
import java.lang.*;
import java.io.*;

/**
* Given a 2D array, find the maximum sum subarray in it
*/
class code
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner input = new Scanner(System.in);

        int t;
        t = input.nextInt();
        for(int i=0;i<t;i++)
        {
            int n,m;
            n = input.nextInt();
            m = input.nextInt();
            int a[][] = new int[n][m];
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    a[j][k]=input.nextInt();
                }
            } 
            findMaxSubMatrix(a);
        }

        // findMaxSubMatrix(new int[][] {
        //                  {1, 2, -1, -4, -20},
        //                  {-8, -3, 4, 2, 1},
        //                  {3, 8, 10, 1, 3},
        //                  {-4, -1, 1, 7, -6}
        //                  });
    }

    /**
    * To find maxSum in 1d array
    * 
    * return {maxSum, left, right}
    */
    public static int[] kadane(int[] a) {
        //result[0] == maxSum, result[1] == start, result[2] == end;
        int[] result = new int[]{Integer.MIN_VALUE, 0, -1};
        int currentSum = 0;
        int localStart = 0;

        for (int i = 0; i < a.length; i++) {
            currentSum += a[i];
            if (currentSum < 0) {
                currentSum = 0;
                localStart = i + 1;
            } else if (currentSum > result[0]) {
                result[0] = currentSum;
                result[1] = localStart;
                result[2] = i;
            }
        }

        //all numbers in a are negative
        if (result[2] == -1) {
            result[0] = 0;
            for (int i = 0; i < a.length; i++) {
                if (a[i] > result[0]) {
                    result[0] = a[i];
                    result[1] = i;
                    result[2] = i;
                }
            }
        }

        return result;
    }

    /**
    * To find and print maxSum, (left, top),(right, bottom)
    */
    public static void findMaxSubMatrix(int[][] a) {
        int cols = a[0].length;
        int rows = a.length;
        int[] currentResult;
        int maxSum = Integer.MIN_VALUE;
        int left = 0;
        int top = 0;
        int right = 0;
        int bottom = 0;

        for (int leftCol = 0; leftCol < cols; leftCol++) {
            int[] tmp = new int[rows];

            for (int rightCol = leftCol; rightCol < cols; rightCol++) {

                for (int i = 0; i < rows; i++) {
                    tmp[i] += a[i][rightCol];
                }
                currentResult = kadane(tmp);
                if (currentResult[0] > maxSum) {
                    maxSum = currentResult[0];
                    left = leftCol;
                    top = currentResult[1];
                    right = rightCol;
                    bottom = currentResult[2];
                }
            }
        }
        System.out.println(maxSum);
    //      System.out.println("MaxSum: " + maxSum + 
    //                          ", range: [(" + left + ", " + top + 
    //                          ")(" + right + ", " + bottom + ")]");
    // }
}
}