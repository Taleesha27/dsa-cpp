#include<bits/stdc++.h>
using namespace std;
//functions
    int sum(int a, int b){
        return a+b;
    }
    int count_digits(int num){
        int count=0;
        // while(num>0){
        //     num /= 10;
        //     count++;
        // }
                // or
        // count = (int)log10(num)+1;   // log10(num) gives the number of times the provided number is divisible by 10 (i.e., log10(7789)=3.89 => 3.89+1=4.89 => int(4.89)=4)
        return count;
        // time complexity = O(log10(n))
    }
    void reverse_num(int num){
        //sample num=10400 output=401
        int reverse_number=0;
        while(num>0){
            int last_digit=num%10;
            reverse_number=(reverse_number*10)+last_digit;
            num /= 10;
        }
        cout<<"Reverse: "<<reverse_number<<endl;
    }
    void palindrome_num(int num){
        int copy_num=num, reverse_num=0;
        while(num>0){
            int last_digit=num%10;
            reverse_num=(reverse_num*10)+last_digit;
            num /= 10;
        }
        if(reverse_num == copy_num) cout<<"Palindrome"<<endl;
        else cout<<"Not palindrome"<<endl;
    }
    void armstrong_num(int num){
        int copy_num=num, sum=0, count=0, last_digit, temp;
        while(num>0){
            num /= 10;
            count++;
        }
        num=copy_num;
        while(num>0){
            last_digit=num%10;
            temp=1;
            for(int i=0;i<count;i++){
                temp *= last_digit;
            }
            sum += temp;
            num /= 10;
        }    
        if(sum == copy_num) cout<<"Armstrong number"<<endl;
        else cout<<"Not armstrong"<<endl;
    }
    void div(int num){
        for(int i=1;i<=num;i++){
            if(num%i == 0){
                cout<<i<<" ";
            }
        }
        cout<<endl;
        // time complexity = O(n)
                // or
        vector <int> divisors;
        for (int i=1;i<=sqrt(num);i++){
            if(num%i == 0){
                divisors.push_back(i);
                if(num/i != i){
                    divisors.emplace_back(num/i);
                }
            }
        }
        sort(divisors.begin(),divisors.end());
        for(auto i: divisors){
            cout<<i<<" ";
        }
    }
    void prime(){
        int num, count=0;
        cout<<"Enter number: ";
        cin>>num;
        for(int i=1;i*i<=num;i++){
            if(num%i == 0){
                count++;
                if(num/i != i){
                    count++;
                }
            }
        }   
        if(count == 2){
            cout<<"Prime";
        }
        else{
            cout<<"Not prime";
        } 
        // time complexity = O(sqrt(N))
    }
    void gcd(){
        // Brutt Force method (having linear time complexity)
        // int num1,num2;
        // cout<<"Enter first number: ";
        // cin>>num1;
        // cout<<"Enter second number: ";
        // cin>>num2;
        // int gcd=1;
        // for(int i=1;i<=min(num1,num2);i++){
        //     if(num1%i==0 && num2%i==0) gcd=i;
        // }
        // cout<<gcd<<endl;
        // gcd=1;
        // // time complexity = O(min(N1,N2))
        //     // or
        // for(int i=min(num1,num2);i>=1;i--){
        //     if(num1%i==0 && num2%i==0){
        //         gcd=i;
        //         break;
        //     }
        // }
        // cout<<gcd;
        // // time complexity = O(min(N!,N2))
        
        // Euclidean algorithm (takes muchg lesser time)
        // states that if a>b then gcd(a,b)->gcd(a-b,b) until any one number becomes 0, when it becomes 0 the other number is the gcd
        // but it can also take a lot of time to execute like gcd(52,10)
        // in more efficient way gcd(a,b) where a>b = gcd(a%b,b) until any one number become 0, then the other will be gcd
        // this way has a better time complexity
        // int n1,n2;
        // cout<<"Enter first number: ";
        // cin>>n1;
        // cout<<"Enter second number: ";
        // cin>>n2;
        // int gcd=1;
        // while(n1>0 && n2>0){
        //     if (n1>n2) n1%=n2;
        //     else n2%=n1;
        // }
        // if(n1==0) gcd=n2;
        // else gcd=n1;
        // cout<<gcd;
        // // time complexity = O(logq(min(N1,N2))) where q=number by it reduces by dividing
    }
    bool comp(pair <int,int> p1, pair <int,int> p2){ // everytime when this func gets false it automatically swaps the elements returning false to it
        if (p1.second < p2.second){
            return true;
        }
        if(p1.second > p2.second){
            return false; // swaps the pair
        }
        if(p1.first > p2.first){
            return true;
        }
        else{
            return false; // swaps the pair
        }
    }
    void Lower_bound(){ // array must be in sorted order, points to the first occurence of the element given and if not found then points to the immediate next greater element of the array
        // time complexity is O(log n)
        int arr[]={10,20,30,40,50,60,70,80,90,100};
        int ind1 = lower_bound(arr,arr+10,20)-arr; // (arr,arr+10,20) gives iterator so to get index of the element '-arr' is mandatory => 1
        int ind2 = lower_bound(arr,arr+10,35)-arr; // points to 40 as it is > 35 (immediate) => 3
        int ind3 = lower_bound(arr,arr+10,102)-arr; // points to end that is after 100, as 102 is not in the array => 10
        cout<<ind1<<" "<<ind2<<" "<<ind3<<endl; // 1 3 10
        vector <int> v;
        v.push_back(10);
        v.emplace_back(20);
        v.push_back(30);
        v.emplace_back(40);
        v.push_back(50);
        v.emplace_back(60);
        v.push_back(60);
        v.emplace_back(80);
        v.push_back(90);
        v.emplace_back(100);
        int in1 = lower_bound(v.begin(),v.end(),60)-v.begin();// gives 5 as first occurence of 60 is at 5th index
        int in2 = lower_bound(v.begin(),v.end(),25)-v.begin(); // gives 2 as 25 is not in vector so 30 is immediate > 25 present in the vector
        int in3 = lower_bound(v.begin(),v.end(),110)-v.begin(); // gives 10 as 110 is not present so it points at the end of the vector
        cout<<in1<<" "<<in2<<" "<<in3<<endl; // 5 2 10
    }
    void Upper_bound(){ // array must be in sorted order, points to the immediate greater element even it exists and if not then also points to next immediate greater element 
        // time complexity is O(log n)
        int arr[] = {10,20,30,40,50,60,70,80,90,100};
        int ind1 = upper_bound(arr,arr+10,30)-arr; // gives 3 even 30 is present at 2nd index
        int ind2 = upper_bound(arr,arr+10,65)-arr; // gives 6 as 70 is immediate > 65
        int ind3 = upper_bound(arr,arr+10,105)-arr; // gives 10 as 105 is not present in array
        cout<<ind1<<" "<<ind2<<" "<<ind3<<endl; // 3 6 10
        vector <int> v;
        v.push_back(10);
        v.emplace_back(20);
        v.push_back(20);
        v.emplace_back(40);
        v.push_back(50);
        v.emplace_back(60);
        v.push_back(70);
        v.emplace_back(80);
        v.push_back(90);
        v.emplace_back(100);
        int in1 = upper_bound(v.begin(),v.end(),20)-v.begin(); // gives 3 as 40 is the immediate greater in the vector
        int in2 = upper_bound(v.begin(),v.end(),85)-v.begin(); // gives 8 as 90 is immediate > 85
        int in3 = upper_bound(v.begin(),v.end(),120)-v.begin(); // gives 10 as 120 is not present in the vector
        cout<<in1<<" "<<in2<<" "<<in3<<endl; // 3 8 10 
    }
//questions
    // 1. find the first occurence of an element in a sorted array. if it does not exists print -1 array=[1,4,4,4,4,9,9,10,11]
        int sol1(int element){
            int arr[] = {1,4,4,4,4,9,9,10,11};
            int ind = lower_bound(arr,arr+9,element)-arr;
            if (ind!=9 && arr[ind]==element) return ind;
            else return -1;
        }
    // 2. find the last occurence of an element in a sorted array. if it does not exists print -1 array=[1,4,4,4,4,9,9,10,11]
        int sol2(int element){
            int arr[] = {1,4,4,4,4,9,9,10,11};
            int ind = upper_bound(arr,arr+9,element)-arr;
            ind--;
            if(ind>=0 && arr[ind]==element) return ind;
            else return -1;
        }
    // 3. find the largest number that is smaller than an element in a sorted array. if no number exists print -1 array=[1,4,4,4,4,9,9,10,11]
        int sol3(int element){
            int arr[] = {1,4,4,4,4,9,9,10,11};
            int ind = lower_bound(arr,arr+9,element)-arr;
            ind--;
            if(ind>=0) return arr[ind];
            else return -1;
        }
    // 4. find the smallest number greater than an element in a sorted array. if no number exists print -1 array=[1,4,4,4,4,9,9,10,11]
        int sol4(int element){
            int arr[] = {1,4,4,4,4,9,9,10,11};
            int ind = upper_bound(arr,arr+9,element)-arr;
            if(ind!=9) return arr[ind];
            else return -1;
        }
//patterns
    void pattern1(int n){
        char stars='*';
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<stars;
            }
            cout<<endl;
        }
    }
    void pattern2(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
    void pattern3(int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void pattern4(int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
    void pattern5(int n){
        for(int i=0;i<n;i++){
            for(int j=n;j>i;j--){
                cout<<"*";
            }
            cout<<endl;
        }
    }
    void pattern6(int n){
        for(int i=n;i>0;i--){
            for(int j=1;j<=i;j++){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void pattern7(int n){
        for(int i=0;i<n;i++){
            //space
            for(int j=n;j>i+1;j--){
                cout<<" ";
            }
            //stars
            for(int j=0;j<2*i+1;j++){
                cout<<"*";
            }
            //space
            for(int j=n;j>i+1;j--){
                cout<<" ";
            }
            cout<<endl;
        }
    }
    void pattern8(int n){
        for(int i=0;i<n;i++){
            //space
            for(int j=0;j<=i;j++){
                cout<<" ";
            }
            //star
            for(int j=0;j<2*n-(2*i+1);j++){
                cout<<"*";
            }
            //space
            for(int j=0;j<=i;j++){
                cout<<" ";
            }
            cout<<endl;
        }
    }
    void pattern9(int n){
        //upper half
        for(int i=0;i<n;i++){
            //space
            for(int j=0;j<n-(i+1);j++){
                cout<<" ";
            }
            //stars
            for(int j=0;j<2*i+1;j++){
                cout<<"*";
            }
            //space
            for(int j=0;j<n-(i+1);j++){
                cout<<" ";
            }
            cout<<endl;
        }
        //lower half
        for(int i=0;i<n;i++){
            //space
            for(int j=0;j<i;j++){
                cout<<" ";
            }
            //stars
            for(int j=0;j<2*n-(2*i+1);j++){
                cout<<"*";
            }
            //space
            for(int j=0;j<i;j++){
                cout<<" ";
            }
            cout<<endl;
        }
    }
    void pattern10(int n){
        for(int i=0;i<2*n-1;i++){
            if(i+1>n){
                for(int j=0;j<2*n-(i+1);j++){
                    cout<<"*";
                }
            }
            else{
                for(int j=0;j<i+1;j++){
                    cout<<"*";
                }
            }
            cout<<endl;
        }
    }
    void pattern11(int n){
        for(int i=0;i<n;i++){
            int start =1 ;
            if(i%2==0){
                start=1;   
            }
            else{
                start=0;
            }
            for(int j=0;j<=i;j++){
                cout<<start;
                start=1-start;
            }
            cout<<endl;
        }
    }
    void pattern12(int n){
        for(int i=1;i<=n;i++){
            //numbers
            for(int j=1;j<=i;j++){
                cout<<j;
            }
            //space
            for(int j=0;j<2*n-(2*i);j++){
                cout<<" ";
            }
            //numbers
            for(int j=i;j>=1;j--){
                cout<<j;
            }
            cout<<endl;
        }
    }
    void pattern13(int n){
        int num=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                cout<<num<<" ";
                num+=1;
            }
            cout<<endl;
        }
    }
    void pattern14(int n){
        for(int i=0;i<n;i++){
            char ch='A';
            for(int j=0;j<=i;j++){
                cout<<ch;
                ch++;
            }
            cout<<endl;
        }
    }
    void pattern15(int n){
        for(int i=n;i>0;i--){
            for(char j='A';j<'A'+i;j++){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void pattern16(int n){
        char ch='A';
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                cout<<ch<<" ";
            }
            ch++;
            cout<<endl;
        }
    }
    void pattern17(int n){
        for(int i=0;i<n;i++){
            //space
            for(int j=0;j<n-(i+1);j++){
                cout<<" ";
            }
            //letter
            char ch='A';
            int breakpoint=(2*i+1)/2;
            for(int j=1;j<=2*i+1;j++){
                cout<<ch;
                if(j<=breakpoint) {ch++;}
                else {ch--;}
            }
            //space
            for(int j=0;j<n-(i+1);j++){
                cout<<" ";
            }
            cout<<endl;
        }
    }
    void pattern18(int n){
        for(int i=0;i<n;i++){
            for(char ch='E'-i;ch<='E';ch++){
                cout<<ch<<" ";
            }
            cout<<endl;
        }
    }
    void pattern19(int n){
        for(int i=0;i<n;i++){
            //stars
            for(int j=0;j<n-i;j++){
                cout<<"*";
            }
            //spaces
            for(int j=0;j<2*i;j++){
                cout<<" ";
            }
            //stars
            for(int j=0;j<n-i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        int initial_space=n+3;
        for(int i=0;i<n;i++){
            //stars
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            //spaces
            for(int j=0;j<2*n-((2*i)+2);j++){
                cout<<" ";
            }
            //stars
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
    void pattern20(int n){
        for(int i=0;i<n;i++){
            //stars
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            //spaces
            for(int j=0;j<2*n-((2*i)+2);j++){
                cout<<" ";
            }
            //stars
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
            cout<<endl;
        }
        for(int i=0;i<n-1;i++){
            //stars
            for(int j=0;j<n-(i+1);j++){
                cout<<"*";
            }
            //spaces
            for(int j=0;j<2*i+2;j++){
                cout<<" ";
            }
            //stars
            for(int j=0;j<n-i-1;j++){
                cout<<"*";
            }
            cout<<endl;
        }
    }
    void pattern21(int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==n-1||j==0||j==n-1){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
    void pattern22(int n){
        for(int i=0;i<2*n-1;i++){
            for(int j=0;j<2*n-1;j++){
                int top=i;
                int left=j;
                int right=(2*n-2)-j;
                int bottom=(2*n-2)-i;
                cout<<(n-min(min(top,bottom),min(left,right)));
            }
            cout<<endl;
        }
    }
// Recursion
    void name(int i,int n){
        if(i>n) return;
        cout<<"Taleesha"<<endl;
        name(i+1,n);
        // time complexity = O(N)
        // space complexity = O(N)
    }
    void countAscending(int i,int n){
        if(i>n) return;
        cout<<i<<endl;
        countAscending(i+1,n);
    }
    void countDescending(int i,int n){
        if(i>n) return;
        cout<<n<<endl;
        countDescending(i,n-1);
    }
    void countAscendingByBacktracking(int i,int n){
        if(i<1)return;
        countAscendingByBacktracking(i-1,n);
        cout<<i<<" ";
    }
    void countDescendingByBacktracking(int i,int n){
        if(i>n)return;
        countDescendingByBacktracking(i+1,n);
        cout<<i<<" ";
    }
    void sumOfFirst_N_NumbersParameterised(int num,int sum){
        if(num<1){
            cout<<"Sum: "<<sum;
            return;
        }
        sumOfFirst_N_NumbersParameterised(num-1,sum+num);   
    }
    int sumOfFirst_N_NumbersFunctional(int num){
        if(num==0)return 0;
        return num+sumOfFirst_N_NumbersFunctional(num-1);
    }
    int factorial(int num){
        if(num==1)return 1;
        return num*factorial(num-1);
        // Time complexity = O(N)
        // Space complexity = O(N) stack space/auxiliary space
    }
    void reverseArray2Ptr(int arr[],int start,int last){
        if(start>=last) return;
        swap(arr[start],arr[last]);
        reverseArray2Ptr(arr,start+1,last-1);
    }
    void reverseArray1Ptr(int arr[],int start){
        if(start>=3) return;
        swap(arr[start],arr[6-start-1]);
        reverseArray1Ptr(arr,start+1);
    }
    bool palindromeString(string str,int i){
        if(i>=str.size()/2) return true;
        if(str[i]!=str[str.size()-i-1]) return false; 
        return palindromeString(str,i+1);
        // Time complexity = O(N/2)
        // Space complexity = O(N/2)
    }
    int fibonacci_num(int num){
        if(num<=1) return num;
        return fibonacci_num(num-1)+fibonacci_num(num-2);
        // Time complexity = O(2^n) approx as each N calls couple of recursion function
    }
// Utility library
    void Pair(){
        pair<int,int>var1={5,7};
        pair<int,pair<int,int>>var2={1,{2,3}};
        pair<int,int>arr[]={{1,2},{3,4},{5,6},{7,8},{9,10}};
        cout<<var1.first<<" "<<var1.second<<endl;
        cout<<var2.first<<" "<<var2.second.first<<" "<<var2.second.second<<endl;
        cout<<arr[0].first<<" "<<arr[0].second<<endl;
        cout<<arr[1].first<<" "<<arr[1].second<<endl;
        cout<<arr[2].first<<" "<<arr[2].second<<endl;
        cout<<arr[3].first<<" "<<arr[3].second<<endl;
        cout<<arr[4].first<<" "<<arr[4].second<<endl;
    }
    void Vector(){
        vector <int> v1; // vector of integer type
        v1.push_back(5); // add 5 to a vector
        v1.emplace_back(10); //add or append 10 to the same vector
        vector <pair<int,char>> v2;// vector of pair type
        v2.push_back({1,'A'}); // {} are mandatory
        v2.emplace_back(2,'B'); // {} are not compulsory
        vector <char> v3(5,'A'); // vector of array of char type with 'A' 5 times
        vector <string> v4(5); // vector of array of string type of size 5 with no elements
        vector <string> v5(v4); // copy the vector 4 in vector 5
        cout<<v1[0]<<" "<<v2[1].first<<" "<<v3[2]<<" "<<v4[3]<<" "<<v5[4]<<endl; // o/p = 5 2 A null null
        cout<<v1[1]<<" "<<v2[1].second<<" "<<v3[3]<<endl; // o/p = 10 B A
        cout<<v2[0].first<<" "<<v2.at(0).second<<endl; // o/p = 1 A
        vector <int> :: iterator i = v1.begin(); // v1.begin() gives the memory address of first element of v1 array
        cout<<&(*i)<<endl; // prints memory location or simple cout<<i
        cout<<*i<<endl;
        vector <char> :: iterator j =v3.end(); // points to location right after the last element of v3
        j--; // now points to the last element of v3 array
        cout<<*j<<endl; // o/p = A
        vector <int> v6;
        v6.push_back(10);
        v6.push_back(20);
        v6.push_back(30);
        v6.push_back(40);
        v6.push_back(50);
        vector <int> :: reverse_iterator k = v6.rend(); // first 50 40 30 20 10 then points location right after 10 i.e., k 10 20 30 40 50
        cout<<*k<<endl; // throws garbage because before 10 we don't have element in v6 so provides random element
        k--; // gives location of 10 in v6 as it behaves as k++ in real v6
        cout<<*k<<endl; // o/p = 10
        vector <int> :: reverse_iterator m = v6.rbegin(); // first 50 40 30 20 10 then points to location of 50
        cout<<*m<<endl; // o/p = 50
        m++; // location of 40 as it behaves like m--
        cout<<*m<<endl; // o/p = 40
        cout<<v6.back()<<endl; // gives last element of v6 o/p = 50
        for(vector <int> :: iterator i = v6.begin(); i != v6.end(); i++){ // vector<int>::iterator is same as "auto"
            cout<<*i<<" ";
        }
        cout<<endl;
        for(auto i:v6){
            cout<<i<<" ";
        }
        cout<<endl;
        //erasing single item from vector
        v6.erase(v6.begin()+1); // erase 20 from v6 as v6.begin()=10 +1= 20 then v6 becomes 10 30 40 50
        for(auto i:v6){
            cout<<i<<" ";
        }
        cout<<endl;
        //erasing couple of elements from vector
        v6.erase(v6.begin()+1,v6.begin()+3); // vector_name.erase(start,end) where end is not included i.e., v6 becomes 10 50
        for(auto i:v6){
            cout<<i<<" ";
        }
        cout<<endl;
        vector <int> v7;
        v7.push_back(10);
        v7.push_back(20);
        v7.push_back(30);
        v7.push_back(40);
        v7.push_back(50);
        v7.push_back(60);
        v7.push_back(70);   
        for(auto i:v7){
            cout<<i<<" ";
        }
        cout<<endl;
        v7.insert(v7.begin(),80); // insert 80 at beginning
        for(auto i:v7){
            cout<<i<<" ";
        }
        cout<<endl;
        v7.insert(v7.begin()+2,2,90); // inserts two 90's at 3rd pos => 80 10 90 90 20 30 40 50 60 70 => vector.insert(pos_to insert, no_of_elements_to_insert, element)
        for(auto i:v7){
            cout<<i<<" ";
        }
        cout<<endl;
        v7.insert(v7.begin()+3,v6.begin(),v6.end()); // insert v6 elements into v7
        for(auto i:v7){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<v7.size(); // provides no of elements in the vector
        cout<<endl;
        v7.pop_back(); // deletes last element of vector
        for(auto i:v7){
            cout<<i<<" ";
        }
        cout<<endl;
        v7.swap(v6); // swap v7 vector with v6
        for(auto i:v7){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:v6){
            cout<<i<<" ";
        }
        cout<<endl;
        v6.swap(v7);
        v6.clear(); // deletes the all elements from the vector
        cout<<v6.empty(); // returns true if vector is empty else false
    }
    void List(){
        list <int> l; // declare a list that is very similar to vectors
        l.push_back(10); // add 10 to li
        l.emplace_back(20); // add or append 20 to li
        l.push_front(30); // add 30 at start and it is very cheap than insert in vector as doubly linked list is created in beckend for it but singly linked list for the vector
        l.emplace_front(40); // add 40 in starting
        // rest operations such as begin, end, rbegin, rend, swap, clear, insert, size, etc are same as vectors
        for(auto i : l){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    void Deque(){
        deque <int> d; // creates deque
        d.push_back(10); // add 10 at last
        d.emplace_back(20); // add 20 at last
        d.push_front(30); // add 30 at front
        d.emplace_front(40); // add 40 at start
        for(auto i : d){
            cout<<i<<" ";
        }
        cout<<endl;
        d.pop_back(); // delete last element
        for(auto i : d){
            cout<<i<<" ";
        }
        cout<<endl;
        d.pop_front(); // delete front element
        for(auto i : d){
            cout<<i<<" ";
        }
        cout<<endl;
        cout<<d.back()<<endl; // show last element
        cout<<d.front()<<endl; // show front element
        // rest operations like begin, end, rbegin, rend, clear, insert, swap, size, are same as vector
    }
    void Stack(){
        stack <int> s1; // declare stack that follows LIFO
        s1.push(10); // add 10 to top
        s1.emplace(20); // push 20 at top and 10 to bottom
        s1.push(30); // push 30 on top and then 20 then 10 at bottom
        s1.emplace(40); // push 40 on top and then 30 20 10 at bottom
        s1.emplace(50); // push 50 on top and then 40 30 20 10 at last
        cout<<s1.top()<<endl; // return 50 as it is on top
        s1.pop(); // remove last in element i.e., top 50
        cout<<s1.top()<<endl; // return new top that is 40
        cout<<s1.size()<<endl; // returns size that 40 30 20 10 which is 4
        cout<<s1.empty()<<endl; // return true if stack is empty else false
        stack <int> s2,s3; // declare two stacks
        s2.swap(s3); // swap two stacks
        // clear operation is also same as vector
        // time complexity is always O(1) i.e., constant for every operation
    }
    void Queue(){
        queue <int> q; // declare queue that follows FIFO
        q.push(10); // push 10 in front
        q.emplace(20); // push 20 after 10
        q.push(30); // push 30 after 20
        q.emplace(40); // push 40 after 30
        cout<<q.front()<<endl; // return 10 as it is front
        cout<<q.back()<<endl; // return 40 as it is end
        q.pop(); // deletes 10 as it is first inned element
        cout<<q.front()<<endl; // return new front that is 20
        cout<<q.back(); // return 40 as it is still in end
        // rest operations such as size, empty, swap, are same as stack
        // time complexity is always O(1) i.e., constant for every operation
    }
    void Priority_queue(){
        // max heap (tree structure is used to maintain it)
        priority_queue <int> p1; // declare priority queue with largest element on top
        p1.push(10); // add 10 on top [time complexity = O(log n)]
        p1.emplace(20); // add 20 on top then 10 as 20>10
        p1.push(5); // add 5 at last => 20 10 5 as 20>10>5
        p1.emplace(25); // add 25 on top then 20 10 5 as 25>20>10>5
        p1.push(15); // add 15 like 25 20 15 10 5 as in descending order
        cout<<p1.top(); // gives 25 as it is on top => 25=max=top [time complexity = O(1) =>constant]
        cout<<endl;
        p1.pop(); // remove 25 from top [time complexity = O(log n)]
        cout<<p1.top(); // gives 20 as it is the new top after 25
        cout<<endl;
        // remaining operations like swap, size, empty are same as queue
        // min heap(tree is used)
        priority_queue <int, vector <int>, greater <int>> p2; // declare priority queue with lowest on top
        p2.push(10); // add 10 at top
        p2.emplace(20); // add 20 after 10 as 20>10
        p2.push(5); // add 5 on top as 5 then 10 then 20 as 5<10<20
        p2.emplace(25); // add 25 at last as 5<10<20<25
        p2.push(15); // add 15 like 5<10<15<20<25 
        cout<<p2.top()<<endl; // gives 5 as it is on top => 5=min=top
        p2.pop(); // removes 5 from top
        cout<<p2.top()<<endl; // gives 10 as it is new top
    }
    void Set(){
        // set store smallest element at last and largest one on the top and again a tree is maintained for it in the backend
        set <int> s; // declare a set that stores elements in 1.sorted ascending order 2.that are unique means no duplicate entries
        s.insert(10); // add 10 => s = {10}
        s.emplace(20); // add 20 => s = {10,20}
        s.insert(5); // s = {5,10,20}
        s.emplace(15); // s = {5,10,15,20}
        s.insert(25); // s = {5,10,15,20,25}
        s.emplace(10); // not add 10 as it is already included in the set => s = {5,10,15,20,25}
        // remaining operations such as swap, size, empty, begin, end, rbegin, rend are same as vectors and insert can also used here in different forms as in vectors to increase efficiency
        auto i = s.find(20); // gives address where 20 found in the set in the memory
        auto j = s.find(30); // address of set.end() that is the address right after the last element address
        cout<<*i<<endl;
        cout<<*j<<endl;
        s.erase(10); // deletes 10 from set but without changing the sorted order => s = {5,15,20,25}
        auto k = s.find(15); // or another type to delete any element.....
        s.erase(k); // .....contd => s = {5,20,25}
        auto start = s.find(5); // ......contd
        auto end = s.find(25); // ......contd
        s.erase(start,end); // ....contd here end is not included => s = {25}
        int count = s.count(10); // if 10 +nt then only one time as set has unique elements and if not then it is zero count so, count return only 0 or 1
        cout<<count<<endl;
        // [time complexity for all the operations on sets = O(log n)]
    }
    void Multiset(){
        // multiset allows duplicate entries in sorted manner (ascending)
        multiset <int> m;// declare multiset of integer datatype
        m.insert(10); // add 10 => m = {10}
        m.emplace(10); // add 10 => m = {10,10}
        m.insert(10); // add 10 => m = {10,10,10}
        m.emplace(20); // add 20 => m = {10,10,10,20}
        m.insert(30); // add 30 => m = {10,10,10,20,30}
        m.emplace(10); // add 10 => m = {10,10,10,10,20,30}
        m.insert(10); // add 10 => m = {10,10,10,10,20,30}
        m.emplace(25); // add 20 => m = {10,10,10,10,20,25,30}
        for(auto i : m) {cout<<i<<" ";}
        cout<<endl;
        cout<<m.count(10)<<endl; // provides 5 as there are 5 10s in the multiset
        m.erase(m.find(10)); // remove one 10 from multiset => m = {10,10,20,30}
        for(auto i : m) {cout<<i<<" ";}
        cout<<endl;
        m.erase(10); // erase all 10 from multiset
        for(auto i : m) {cout<<i<<" ";}
        cout<<endl;
        m.erase(m.find(20),m.find(30)); // find 20 in multiset then remove all elements before 30 in the multiset that is 30 is excluded
        for(auto i : m) {cout<<i<<" ";}
        cout<<endl;
        // rest all the functions are same as set
    }
    void Unordered_set(){
        // stores unique elements in unsorted order that is no particular manner so output can be different in everytime
        unordered_set <int> u; // declare unordered set of integers 
        // [time complexity = O(1) => constant time for all the operations]
        // [very very rare cases time complexity = O(n) => linear time]
        // all the functions are same as set except for lower-bound and upper-bound functions
    }
    void Map(){
        // map has key,value pair where keys are unique and in sorted order
        map <int,int> m1; // declare map of integer type
        m1[1]=10; // add 10 for key 1
        m1.emplace(3,30); // add 30 for key 3
        m1.insert({2,20}); // add 20 for key 2
        for(auto i : m1){
            cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<m1[2]<<endl; // search 2 as key then return 20 = value for key 2
        cout<<m1[4]<<endl; // key 4 doesn't exist so returns null as its value that is 0
        auto i = m1.find(3); // find key as 3
        cout<<(*i).second<<endl; // returns 30 = value of key 3
        map <int,pair<int,int>> m2; // declare map of one key and a pair of multiple values
        map <pair<int,int>,int> m3; // declare map of two keys having the same value
        m3[{4,5}]=40; // add 40 for key {4,5}
        m3.insert({{6,7},50}); // add 50 for key {6,7}
        m3.emplace(make_pair(8,9),60); // add 60 for key {8,9}
        // remaining operations like swap, erase, size, empty are same as above mentioned
        // [time complexity = O(log n)]
    }
    void Multimap(){
        // same as map except it can store duplicate keys in sorted order
        // only map_name[key] doesn't work
    }
    void Unordered_map(){
        // same as map but not sorted keys not duplicate keys, just a key value pair in any random order
        // [time complexity = O(1) in almost every cases in very rare or worst cases it is O(n)]
    }
// Algorithms
    void Sort_array(){
        int arr1[]={10,30,20,50,40};
        for(int i=0;i<=4;i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
        sort(arr1,arr1+4); // sort array in ascending order
        for(int i=0;i<=4;i++){
            cout<<arr1[i]<<" "; // 10 20 30 40 50
        }
        cout<<endl;
        int arr2[]={60,100,80,70,50};
        for(int i=0;i<=4;i++){
            cout<<arr2[i]<<" "; // 10 20 30 40 50
        }
        cout<<endl;
        sort(arr2+2,arr2+4); // sort array from 2 to third element as last is not included
        for(int i=0;i<=4;i++){
            cout<<arr2[i]<<" "; // 60 100 70 80 50
        }
        cout<<endl;
        sort(arr2,arr2+4,greater<int>()); // sort array in descending order
        for(int i=0;i<=4;i++){
            cout<<arr2[i]<<" "; // 60 100 70 80 50
        }
        cout<<endl;
    }
    void Sort_vector(){
        vector <int> v;
        v.push_back(10);
        v.emplace_back(30);
        v.push_back(20);
        v.emplace_back(50);
        v.push_back(40);
        for(auto i : v){
            cout<<i<<" "; //10 30 20 50 40
        }
        cout<<endl;
        sort(v.begin(),v.end()); // sort vector from starting to end
        for(auto i: v){
            cout<<i<<" "; // 10 20 30 40 50
        }
        cout<<endl;
    }
    void Sort_pairArray(){
        pair <int,int> p[]={{1,20},{3,30},{5,50},{4,40},{2,20}};
        for(auto i : p){
            cout<<i.first<<" "<<i.second<<" ";
            cout<<endl;
        }
        cout<<endl;
        //ques
        // now sorting this pair array as
        // 1.according to second element
        // 2.if second elements are same then desceding order of first element
        // => p = {{2,20},{1,20},{3,30},{4,40},{5,50}} must be the output
        // solution
        sort(p,p+5,comp); // here comp is a boolean function which must be defined
        for(auto &i : p){
            cout<<i.first<<" "<<i.second<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    void builtin_popcount(){ // returns the number of 1s in the binary of the digits passed
        int num1 = 7;
        cout<<__builtin_popcount(num1)<<endl;
        long long num2 = 16782395748939784;
        cout<<__builtin_popcountll(num2)<<endl;
    }
    void next_permutation(){ // returns all the possible ways of writing a string
        string s1 = "231";
        do{
            cout<<s1<<endl;
        }
        while(next_permutation(s1.begin(),s1.end())); // returns three permutation start with the string itself as the next must be greater than of this
        cout<<"--------"<<endl;
        string s2 = "231";
        sort(s2.begin(),s2.end()); // sorts the string as 123
        do{
            cout<<s2<<endl;
        }
        while(next_permutation(s2.begin(),s2.end())); // returns all the 6 permutations as it is sorted that is same as 123
    }
    void max_min(){
        int arr[] = {10,20,30,60,90,100,50,80,70,40};
        cout<<*max_element(arr,arr+10)<<endl; // returns address iterator of max array element then dereferencing it using * gives element value
        cout<<*min_element(arr,arr+10)<<endl; // returns address iterator of max array element then dereferencing it using * gives element value
    }
// Hashing
    void numberHashing_hashCountFreq(int arr[],int size){
        // pre-computation
        int hashArray[size]={0};
        for(int i=0;i<size;i++){
            hashArray[arr[i]]+=1;
        }
        int num;
        cout<<"Enter how many number's you want to count frequency of: ";
        cin>>num;
        while(num--){
            int element;
            cout<<"Enter element to search: ";
            cin>>element;
            // fetching
            cout<<"Freq of "<<element<<" is: "<<hashArray[element]<<endl;
        }
    }
    void mapHashing_countFreq(int arr[],int size){
        // pre-computation
        map<int,int> m;
        for(int i=0;i<size;i++){
            m[arr[i]]++;
        }
        // map stores the values in sorted order
        /*for(auto i:m){
            cout<<i.first<<":"<<i.second<<endl; // i.first=key and i.second=value
        }*/
        int num;
        cout<<"Enter total number of elements you wanna get frequency of: ";
        cin>>num;
        while(num--){
            int element;
            cout<<"Enter element to get freq: ";
            cin>>element;
            // fetching
            cout<<"Frequency of "<<element<<" is: "<<m[element]<<endl;
        }
        // it is more memory efficient than arrayHashing as it contains only the elements that are stored but arrays must contains the size of largest element
        // eg; if user has entered {1,2,3,1,20} then hashArray must be of size 20 i.e., hash[20]
        // but, in map only 5 keys are to be stored and fetching of any unavailable element returns 0
        // Time complexity is storing + fetching of elements =O(log N) in all, best,avg, and worst cases. N is no of elements in the map
        // in unordered map time complexity of best and avg cases is O(1) and O(N) in worst case which is very rare like once in a blue moon nad that is why it should be used first with first priority than map. N is no of elements in the map 
        // maps are internally created as 1. division method 2. folding method 3. mid square method
        // only division method can be asked and very rare
        // eg, [28,46,79,93,84]
        // arr[i]%10 => [8,6,9,3,4]
        // then go for array hashing
        // now there is a concept of linear chaining
        // [28,48,138,18,93]
        // arr[i]%10 => [8=>18->28->48->138
        //               3=>93]
        // this is done in sorted manner and using linked list
        // fetching is also done using binary search in linked list and in minimal time
        // [3,13,23,33,43,53,63,73,83,93,103,........,10003]
        // arr[i]%10 => [0
        //               1
        //               2
        //               3=>3->13->23->33->.......->10003]
        // now when all the elements wants to go to the same hash area, collision happens and other memory spaces are wasted kind of and fetching freq also takes a lot of time
        // also this is the reason of worst case time complexity
        // in map key can be any data structure but in unordered map it can only be an indiviadual data structure i.e., pair<int,int> can't be a key
    }
    void mapHashing_countHighFreq(int arr[],int size){
        map<int,int> m;
        for(int i=0;i<size;i++){
        m[arr[i]]++; 
        }
        int highestFreqElement=0;
        for(auto i: m){
            if(i.second>highestFreqElement) highestFreqElement = i.second;
        }
        for(auto i : m){
            if(i.second==highestFreqElement) cout<<"The highest frequency element is: "<<i.first<<endl;
        }
    }
    void mapHashing_countLowFreq(int arr[],int size){
        map<int,int> m;
        for(int i=0;i<size;i++){
            m[arr[i]]++;
        }
        int lowestFreqElement=m[1];
        for(auto i : m){
            if(i.second<lowestFreqElement) lowestFreqElement=i.second;
        }
        for(auto i : m){
            if(i.second==lowestFreqElement) cout<<"The lowest frequency element is: "<<i.first<<endl;
        }
    }
    void charHashing_countFreq(string str,int size){
        // if str has only lower case letters
        // pre-computation
        int hash[26]={0};
        for(int i=0;i<size;i++){
            hash[str[i]-'a']++;
        }
        int num;
        cout<<"Enter how many char's frequency you want to fetch: ";
        cin>>num;
        while(num--){
            char ch;
            cout<<"Enter character to get freq: ";
            cin>>ch;
            // fetching
            cout<<"Frequency of "<<ch<<" is: "<<hash[ch-'a']<<endl;
        }
        // in character hashing if it is not known that lower case letters are included or upper case we use hash array of size 256 as there are 256 total characters
        // in such case no need to do "-'a'" as in line 1029 and 1039 just hash[ch] will do the task
        // as 'a' will automatically goes to hash[96] and 'A' to hash[65].....and so on
    }
// Sorting
    void selection_sort(int arr[],int n){
        // select the min and swap to the first
        for(int i=0;i<=n-2;i++){
            int min_ind=i;
            for(int j=i;j<=n-1;j++){
                if(arr[j]<arr[min_ind]) min_ind=j;
            }
            int temp=arr[i];
            arr[i]=arr[min_ind];
            arr[min_ind]=temp;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        // time complexity = O(n^2) -> best, worst, avg for all
    }
    void bubble_sort(int arr[],int n){
        // inverse of selection sort
        // push max element to the last place by adjacent swap
        // [13,52,46,9,8,16]
        // 1. [13,52] no need to swap 
        //    [52,46] swap -> [46,52]
        //    [52,9] swap -> [9,52]
        //    [52,8] swap -> [8,52]
        //    [52,16] swap -> [16,52]
        // array = [13,46,9,8,16,52] => 52 is max and at last
        // 2. [13,46] no swap
        //    [46,9] swap -> [9,46]
        //    [46,8] swap -> [8,46]
        //    [46,16] swap -> [16,46]
        //    no need to check 46 and 52 
        // array = [13,9,8,16,46,52] => 46 is max and at last
        // repeat steps until array sorts
        for(int i=n-1;i>=1;i--){
            int swap_count=0;
            for(int j=0;j<=i-1;j++){ // if j<=i then last element will have no adjacent element to compare with and throws a runtime error(accessing an element which is not present, throws it)
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    swap_count++;
                }
            }
            if(swap_count==0) break;
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        // time complexity = O(n^2) => for worst and avg cases
        // time complexity for best case is O(n) after done some optimization
    }
    void insertion_sort(int arr[],int n){
        // takes an element and places it in its correct place
        // [14,9,15,12,6,8,13]
        // 1. [14]
        // 2. [14,9] swap -> [9,14]
        // 3. [9,14,15] no swap
        // 4. [9,14,15,12] swap -> [9,12,14,15]
        // 5. [9,12,14,15,6] swap -> [6,9,12,14,15]
        // 6. [6,9,12,14,15,8] swap -> [6,8,9,12,14,15] 
        // 7. [6,8,9,12,14,15,13] swap -> [6,8,9,12,13,14,15] sorted
        for(int i=0;i<n;i++){
            for(int j=i;j>0 && arr[j-1]>arr[j];j--){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        } 
        // time complexity = O(n^2) => for worst and avg cases
        // time complexity for best case = O(n)
    }
    // merge sort
        /*divide and merge
        Time complexity = O(Nlog2(N)) for worst case
        O(log2(n))=>divide O(n)=>merge
        Space compplexity = O(N) for worst case only in merge not in divide*/
            void mergea(vector <int> &arr,int low,int mid,int high){
                int left=low,right=mid+1;
                vector <int> temp;
                while(left<=mid && right<=high){
                    if(arr[left]<=arr[right]){
                        temp.push_back(arr[left]);
                        left++;
                    }
                    else{
                        temp.push_back(arr[right]);
                        right++;
                    }
                }
                while(left<=mid){
                    temp.push_back(arr[left]);
                    left++;
                }
                while(right<=high){
                    temp.push_back(arr[right]);
                    right++;
                }
                for(int i=low;i<=high;i++){
                    arr[i]=temp[i-low];
                }
            }
            void div(vector <int> &arr,int low,int high){
                int mid=(low+high)/2;
                if(low>=high) return;
                div(arr,low,mid);
                div(arr,mid+1,high);
                mergea(arr,low,mid,high);
            }
    // quick sort
        /*divide and conquer
        slightly better than merge sort as it does not uses any extra data structure or array so reduces space complexity
        can be used to sort in ascending order and with minor changes can used to sort in descending order too
        1. pick a pivot element that can be first, last, middle, or random element in the array
        2. place the pivot element to its correct place in the sorted array
        time complexity = O(nlogn) not log base 2 cause array is dividing in two arrays but not in the power of two or equally like in merge sort
        space complexity = O(1) as not using any additional array*/
            int pivot_ind(vector <int> &arr,int low,int high){
                int pivot = arr[low], i = low, j = high;
                while(i<j){
                    while(arr[i]<=pivot && i<=high-1) i++; // finds first element greater than pivot
                    while(arr[j]>pivot && j>=low+1) j--; // finds first element smaller than pivot
                    if(i<j) swap(arr[i],arr[j]);
                }
                swap(arr[low],arr[j]);
                return j;
            }
            void sort(vector <int> &arr,int low,int high){
                if(low<high){
                    int p_ind = pivot_ind(arr,low,high);
                    sort(arr,low,p_ind-1);
                    sort(arr,p_ind+1,high);
                }
                else return;
            }

// Arrays
    // medium questions on arrays
        // 5.(ii) stock buy and sell (best time to buy and sell stock multiple times)
            int maxprofit(int price[],int size,int ind,int buyornot){
        int maxxprofit;
        if(ind==size) return 0;
        if(buyornot==1){ // we can buy stock
            int buy=-price[ind]+maxprofit(price,size,ind+1,0); // profit=sell-buy => buy is -ve and sell is +ve
            int notbuy=0+maxprofit(price,size,ind+1,1);
            maxxprofit=max(buy,notbuy);
        }
        else{ // we can't buy stock as we are already holding a stock
            int sell=price[ind]+maxprofit(price,size,ind+1,1);
            int notsell=0+maxprofit(price,size,ind+1,0);
            maxxprofit=max(sell,notsell);
        }
        return maxxprofit;
    }
    // hard questions on arrays
        // 1.(i) find element at given place in pascal triangle
            int pascaltriangleelement(int r,int c){
            int res=1;
            for(int i=0;i<c;i++){ // time complexity = O(col-1)
                res=res*(r-i);
                res=res/(i+1);
            }
            return res;
        }
        // 10. counting inversions optimal sol
            // int cnt=0; // not use in interviews mosltly discouraged
            int Merge(vector <int> &arr,int low,int mid,int high){
                int left=low,right=mid+1;
                int cnt=0;
                vector <int> temp;
                while(left<=mid && right<=high){
                    if(arr[left]<=arr[right]){
                        temp.push_back(arr[left]);
                        left++;
                    }
                    else{
                        temp.push_back(arr[right]);
                        cnt+=mid-left+1;
                        right++;
                    }
                }
                while(left<=mid){
                    temp.push_back(arr[left]);
                    left++;
                }
                while(right<=high){
                    temp.push_back(arr[right]);
                    right++;
                }
                for(int i=low;i<=high;i++) arr[i]=temp[i-low];
                return cnt;
            }
            int Div(vector <int> &arr,int low,int high){
            int mid=(low+high)/2;
            int count=0;
            if(low>=high) return count;
            count+=Div(arr,low,mid);
            count+=Div(arr,mid+1,high);
            count+=Merge(arr,low,mid,high);
            return count;
        }
        // 11. counting reverse pairs optimal sol
            void Mergee(vector <int> &arr,int low,int mid,int high){
                int left=low;
                int right=mid+1;
                vector <int> temp;
                while(left<=mid && right<=high){
                    if(arr[left] <= arr[right]){
                        temp.push_back(arr[left]);
                        left++;
                    }
                    else{
                        temp.push_back(arr[right]);
                        right++;
                    }
                    while(left<=mid){
                        temp.push_back(arr[left]);
                        left++;
                    }
                    while(right<=high){
                        temp.push_back(arr[right]);
                        right++;
                    }
                    for(int i=low;i<=high;i++) arr[i]=temp[i-low];
                }
            }
            int countReversePairs(vector <int> &arr,int low,int mid, int high){
                int right=mid+1;
                int count=0;
                // time complexity = n as every element is iterated only once
                for(int i=low;i<=mid;i++){ 
                    while(right<=high && arr[i]>2*(arr[right])) right++;
                    count+=right-(mid+1);
                }
                return count;
            }
            int Divv(vector <int> &arr,int low,int high){
                int cnt=0;
                if(low>=high) return cnt;
                int mid=(low+high)/2;
                cnt+=Divv(arr,low,mid);
                cnt+=Divv(arr,mid+1,high);
                cnt+=countReversePairs(arr,low,mid,high);
                Mergee(arr,low,mid,high);
                return cnt;
            }

// Binary search
    // recursive code
        int binarySearch(int arr[],int low,int high, int target){
        if(low>high) return -1;
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]) return binarySearch(arr,mid+1,high,target);
        return binarySearch(arr,low,mid-1,target);
    }

// Binary search on answers in the pattern to find minimum of maximum => min(max) or maximum of minimum => max(min)
    // 1. aggressive cows (linear approach)
        void aggressive_cows(vector <int> arr,int cows,int size){
        int minn=arr[0], maxx=arr[0];
        for(int i=0;i<size;i++){
            minn=min(minn,arr[i]);
            maxx=max(maxx,arr[i]);
        }
        int minpossibledist=0;
        for(int i=1;i<maxx-minn;i++){ // time complexity = O(max-min)
            int cow=1; // one cow is already placed
            int prevcow=arr[0]; // first cow should always be at first position to minimise the distance
            for(int j=1;j<size;j++){ // time complexity = O(n)
                if(arr[j]-prevcow >= i){
                    cow++; // next cow is placed
                    prevcow=arr[j]; // the next cow is now at previous position to calculate the distance
                }
            }
            if(cow >= cows) minpossibledist=i; // the minimum distance (i) is possible => go for next increment as to find the max(min)
            else{ // if cows are not placed successfully at this distance (i) then the max dist was previous i
                cout<<"Maximum of minimum distance: "<<i-1;
                break;
            }
        }
    }

// linked list
    // single linked list
        struct Node{
                public:
                    int data;
                    Node* next;
                    Node(int data1, Node* next1){
                        data=data1;
                        next=next1;
                    }
            };
        class node{
            public:
                int data;
                node* next=nullptr;
                node(int data1) : data(data1){}
        };
        // basic operations
            // convert array into linked list
                class head{
                    public: 
                        int data;
                        head* next=nullptr;
                        head(int data1) : data(data1){}
                };
                head* arrtolinkedlist(vector <int> &arr, int size){
                    head* headptr=new head(arr[0]);
                    head* tempptr=headptr;
                    for(int i=1;i<size;i++){
                        head* var=new head(arr[i]);
                        tempptr->next=var;
                        tempptr=var; // or tempptr=tempptr->next;
                    }
                    return headptr;
                }
            // traversal
                void print(head* headptr){
                    if(headptr == NULL) return;
                    while(headptr){
                        cout<<headptr->data<<" ";
                        headptr=headptr->next;
                    }
                }
            // length
                int lengthoflinkedlist(head* hptr){
                    if(hptr == NULL) return 0;
                    head* temphptr=hptr;
                    int length=0;
                    while(temphptr){
                        temphptr=temphptr->next;
                        length++;
                    }
                    return length;
                }
            // search an element
                bool search(head* headptr, int target){
                    head* tempheadptr=headptr;
                    while(tempheadptr){
                        if(tempheadptr->data == target) return true;
                        tempheadptr=tempheadptr->next;
                    }
                    return false;
                }
            // deletion
                // 1. head
                    head* deletehead(head* hptr){
                        if(hptr == nullptr) return hptr;
                        head* tempheadptr=hptr;
                        hptr=hptr->next;
                        delete tempheadptr; // free(tempheadptr); if memory allocated using malloc
                        return hptr;
                    }
                // 2. tail
                    head* deletetail(head* hptr){
                        if(hptr==nullptr || hptr->next==nullptr) return hptr;
                        head* temphptr=hptr;
                        while(temphptr->next->next) temphptr=temphptr->next;
                        delete temphptr->next;
                        temphptr->next=nullptr;
                        return hptr;
                    }
                // 3. specific position (k-th element) 
                    head* deleteposition(head* hptr, int k){
                        int length=lengthoflinkedlist(hptr);
                        if(hptr == NULL) return hptr;
                        else if(k > length) return hptr;
                        else if(k == 1) return deletehead(hptr);
                        else if(k == length) return deletetail(hptr);
                        else{
                            int cnt=1;
                            head* temphptr=hptr;
                            while(cnt < k-1){ // time complexity = O(k)
                                temphptr=temphptr->next;
                                cnt++;
                            }
                            head* nodetodelete=temphptr->next;
                            temphptr->next=temphptr->next->next;
                            delete nodetodelete;
                        }
                        return hptr;
                    }
                // 4. specific value
                    head* deleteelement(head* hptr, int val){
                        head* temphptr=hptr;
                        head* prev=NULL;
                        if(hptr == NULL) return hptr;
                        else if(hptr->data == val){ // delete head
                            hptr=hptr->next;
                            delete temphptr;
                        }
                        else{
                            while(temphptr){
                                if(temphptr->data == val){
                                    prev->next=prev->next->next;
                                    delete temphptr;
                                    break;
                                }
                                prev=temphptr;
                                temphptr=temphptr->next;
                            }
                        }
                        return hptr;
                    }
            // insertion
                // 1. head
                    head* inserthead(head* hptr, int val){
                        head* newhptr=new head(val);
                        newhptr->next=hptr;
                        return newhptr;
                    }
                // 2. tail
                    head* inserttail(head* hptr, int val){
                        head* newnode=new head(val);
                        if(hptr == NULL) return newnode;
                        head* temphptr=hptr;
                        while(temphptr->next) temphptr=temphptr->next;
                        temphptr->next=newnode;
                        newnode->next=NULL;
                        return hptr;
                    }
                // 3. specific position
                    head* insertatposition(head* hptr, int pos, int val){
                        head* newnode=new head(val);
                        head* temphptr=hptr;
                        int length=lengthoflinkedlist(hptr);
                        if(hptr==NULL && pos==1) return newnode;
                        else if(pos<1 || pos>length+1){
                            cout<<"Position is out of boundaries, hence insertion fails!!"<<endl;
                            return hptr;
                        }
                        else if(pos==1){
                            newnode->next=hptr;
                            hptr=newnode;
                        }
                        else{
                            int cnt=0;
                            while(temphptr){
                                cnt++;
                                if(cnt == pos-1){
                                    newnode->next=temphptr->next;
                                    temphptr->next=newnode;
                                    break;
                                }
                                temphptr=temphptr->next;
                            }
                        }
                        return hptr;
                    }
                // 4. specific value position
                    head* insertatotherelementplace(head* hptr, int val, int newval){
                    head* newnode=new head(newval);
                    if(hptr==NULL) return hptr;
                    if(hptr->data == val){
                        newnode->next=hptr;
                        return newnode;
                    }
                    head* temphptr=hptr;
                    while(temphptr->next){
                        if(temphptr->next->data == val){
                            newnode->next=temphptr->next;
                            temphptr->next=newnode;
                            break;
                        }
                        temphptr=temphptr->next;
                    }
                    return hptr;
                }
        // medium problems
            // 1. middle node of list
                // brute force sol
                    head* middlenode1(head* hptr){
                        int length=lengthoflinkedlist(hptr); // time complexity = O(n)
                        if(hptr==NULL){
                            cout<<"Empty list";
                            return NULL;
                        }
                        if(length==1) return hptr;
                        int midposition=length/2;
                        head* midnode=hptr;
                        while(midposition > 0){ // time complexity = O(n/2)
                            midnode=midnode->next;
                            midposition--;
                        }
                        return midnode;
                    }
                // optimal sol (tortoise and hare algo)
                    head* middlenode2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        head* slow=hptr;
                        head* fast=hptr;
                        while(fast!=NULL && fast->next!=NULL){ // time complexity = O(n/2)
                            slow=slow->next;
                            fast=fast->next->next;
                        }
                        head* midnode=slow;
                        return midnode;
                    }
            // 2. reverse the list
                // brute force/iterative approach
                    head* reverselist1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        stack <int> st; // space complexity = O(n)
                        head* temphptr=hptr;
                        while(temphptr){ // time complexity = O(n)
                            st.push(temphptr->data); // time complexity = O(1)
                            temphptr=temphptr->next;
                        }
                        temphptr=hptr;
                        while(temphptr){ // time complexity = O(n)
                            temphptr->data=st.top(); // time complexity = O(1)
                            st.pop(); // time complexity = O(1)
                            temphptr=temphptr->next;
                        }
                        return hptr;
                    }
                // better sol by swapping links
                    head* reverselist2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        head* temphptr=hptr;
                        head* nextelement;
                        head* prevelement=NULL;
                        while(temphptr){ // time complexity = O(n)
                            nextelement=temphptr->next;
                            temphptr->next=prevelement;
                            prevelement=temphptr;
                            temphptr=nextelement;
                        }
                        head* newhead=prevelement;
                        return newhead;
                    }
                // recursive approach
                    head* reverselist3(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        head* newhead=reverselist3(hptr->next); // time complexity = O(n), space complexity = O(n) because of recursive calls
                        head* nextelement=hptr->next;
                        nextelement->next=hptr;
                        hptr->next=NULL;
                        return newhead;
                    }
            // 3. detect a loop
                head* arrtolooplinkedlist(vector <int> &arr){
                        int size=arr.size();
                        head* hptr=arrtolinkedlist(arr, size);
                        head* temphptr=hptr;
                        int loopstart=3; // (say)
                        head* loopnode=NULL;
                        while(temphptr->next){ // time complexity = O(n)
                            loopstart--;
                            if(loopstart == 0) loopnode=temphptr;
                            temphptr=temphptr->next;
                        }
                        temphptr->next=loopnode;
                        return hptr;
                    }
                    // brute force sol
                        bool checkloop1(head* hptr){
                            if(hptr==NULL || hptr->next==NULL) return false;
                            map <head*, int> hash; // space complexity = O(n)
                            head* temphptr=hptr;
                            while(temphptr){ // time complexity = O(n)
                                if(hash.find(temphptr) != hash.end()) return true; //  time complexity = O(logn)
                                hash[temphptr]=1; // time complexity = O(logn)
                                temphptr=temphptr->next;
                            }
                            return false;
                        }
                    // optimal sol
                        bool checkloop2(head* hptr){
                            if(hptr==NULL || hptr->next==NULL) return false;
                            head* slow=hptr;
                            head* fast=hptr;
                            while(fast!=NULL && fast->next!=NULL){ // time complexity = O(n)
                                slow=slow->next;
                                fast=fast->next->next;
                                if(slow == fast) return true;
                            }
                            return false;
                        }
            // 4. starting node of loop in a list
                // brute force sol
                    head* loopnode1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL){
                            cout<<"No loop"<<endl;
                            return NULL;
                        }
                        map <head*,int> hash; // space complexity = O(n)
                        head* temphptr=hptr;
                        head* loopnode=NULL;
                        while(temphptr){ // time complexity = O(n)
                            if(hash.find(temphptr) != hash.end()){ // time complexity = O(logn)
                                loopnode=temphptr;
                                break;
                            }
                            hash[temphptr]=1; // time complexity = O(logn)
                            temphptr=temphptr->next;
                        }
                        return loopnode;
                    }
                // optimal sol
                    head* loopnode2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL){
                            cout<<"No loop"<<endl;
                            return NULL;
                        }
                        // find if loop exists or not
                        head* slow=hptr;
                        head* fast=hptr;
                        head* loopnode=NULL;
                        bool loop=false;
                        while(fast!=NULL && fast->next!=NULL){ // time complexity = O(n)
                            slow=slow->next;
                            fast=fast->next->next;
                            if(slow == fast){
                                loop=true;
                                break;
                            }
                        }
                        // find first node
                        if(loop == true){
                            slow=hptr; // or fast => one of them should be taken
                            while(slow != fast){ // time complexity = O(firstnode position)
                                slow=slow->next;
                                fast=fast->next;
                            }
                            loopnode=slow; // or fast as both are at same node
                        }
                        return loopnode;
                    }
            // 5. length of loop
                // brute force sol
                    int lengthofloop1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return 0;
                        // if loop
                        map <head*, int> hash; // space complexity = O(n)
                        head* temphptr=hptr;
                        head* loopnode=NULL;
                        bool loop=false;
                        while(temphptr){ // time complexity = O(n)
                            if(hash.find(temphptr) != hash.end()){ // time complexity = O(logn)
                                loop=true;
                                loopnode=temphptr;
                                break;
                            }
                            hash[temphptr]=1; // time complexity = O(logn)
                            temphptr=temphptr->next;
                        }
                        // length
                        if(loop == true){
                            int length=1;
                            head* temploopnode=loopnode->next;
                            while(temploopnode != loopnode){ // time complexity = O(lengthofloop)
                                length++;
                                temploopnode=temploopnode->next;
                            }
                            return length;
                        }
                        return 0;
                    }
                // better sol
                    int lengthofloop2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return 0;
                        map <head*,int> hash; // space complexity = O(n)
                        head* temphptr=hptr;
                        int cnt=1;
                        int length=0;
                        while(temphptr){ // time complexity = O(n)
                            if(hash.find(temphptr) != hash.end()){ // time complexity = O(logn)
                                int loopnodepos=hash[temphptr];
                                length=cnt-loopnodepos;
                                break;
                            }
                            hash[temphptr]=cnt; // time complexity = O(logn)
                            cnt++;
                            temphptr=temphptr->next;
                        }
                        return length;
                    }
                // optimal sol
                    int lengthofloop3(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return 0;
                        // if loop
                        head* slow=hptr;
                        head* fast=hptr;
                        bool loop=false;
                        while(fast!=NULL && fast->next!=NULL){ // time complexity = O(n)
                            slow=slow->next;
                            fast=fast->next->next;
                            if(slow==fast){
                                loop=true;
                                break;
                            }
                        }
                        // length
                        if(loop==true){
                            int length=1;
                            fast=slow->next;
                            while(fast!=slow){ // time complexity = O(lengthofloop)
                                length++;
                                fast=fast->next;
                            }
                            return length;
                        }
                        return 0;
                    }
            // 6. check if list is palindrome
                // brute force sol
                    bool palindromelist1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return true;
                        stack <int> st; // space complexity = O(n)
                        head* temphptr=hptr;
                        while(temphptr){ // time complexity = O(n)
                            st.push(temphptr->data); // time complexity = O(1)
                            temphptr=temphptr->next;
                        }
                        temphptr=hptr;
                        while(temphptr){ // time complexity = O(n)
                            if(temphptr->data != st.top()) return false; // time complexity = O(1)
                            temphptr=temphptr->next;
                            st.pop(); // time complexity = O(1)
                        }
                        return true;
                    }
                // optimal sol
                    bool palindromelist2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return true;
                        // finding middle half
                        head* slow=hptr;
                        head* fast=hptr;
                        // find middle
                        while(fast->next!=NULL && fast->next->next!=NULL){ // time complexity = O(n/2)
                            slow=slow->next;
                            fast=fast->next->next;
                        }
                        head* mid=slow->next;
                        // reverse second half
                        head* nextelement;
                        head* prevelement=NULL;
                        while(mid){ // time complexity = O(n/2)
                            nextelement=mid->next;
                            mid->next=prevelement;
                            prevelement=mid;
                            mid=nextelement;
                        }
                        head* sechalfhead=prevelement;
                        // compare both halves
                        head* temphptr=hptr;
                        while(sechalfhead){ // time complexity = O(n/2)
                            if(temphptr->data == sechalfhead->data){
                                temphptr=temphptr->next;
                                sechalfhead=sechalfhead->next;
                            }
                            else break;
                        }
                        // before returning true just reverse second half back to preserve the original list
                        head* prev=NULL;
                        while(prevelement){ // time complexity = O(n/2)
                            nextelement=prevelement->next;
                            prevelement->next=prev;
                            prev=prevelement;
                            prevelement=nextelement;
                        }
                        if(sechalfhead) return false;
                        return true;
                    }
            // 7. grouping odd and even position nodes inside the list
                // brute force sol
                    head* groupoddeven1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        vector <int> v;
                        head* temphptr=hptr;
                        while(temphptr){ // time complexity = O(n/2)
                            v.push_back(temphptr->data);
                            if(temphptr->next == NULL) break;
                            temphptr=temphptr->next->next;
                        }
                        temphptr=hptr->next;
                        while(temphptr){ // time complexity = O(n/2)
                            v.push_back(temphptr->data);
                            if(temphptr->next == NULL) break;
                            temphptr=temphptr->next->next;
                        }
                        temphptr=hptr;
                        int i=0;
                        while(temphptr){ // time complexity = O(n)
                            temphptr->data=v[i];
                            i++;
                            temphptr=temphptr->next;
                        }
                        return hptr;
                    }
                // optimal sol
                    head* groupoddeven2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        head* oddhead=hptr;
                        head* evenhead=hptr->next;
                        head* tempevenhead=evenhead;
                        while(tempevenhead!=NULL && tempevenhead->next!=NULL){ // time complexity = O(n)
                            oddhead->next=oddhead->next->next;
                            tempevenhead->next=tempevenhead->next->next;
                            oddhead=oddhead->next;
                            tempevenhead=tempevenhead->next;
                        }
                        oddhead->next=evenhead;
                        return hptr;
                    }
            // 8. remove a node from last of the list
                // brute force sol
                    head* removenodelast1(head* hptr, int nodeposend){
                        if(hptr==NULL || hptr->next==NULL){
                            if(nodeposend==1){
                                delete hptr;
                                return NULL;
                            }
                            return hptr;
                        }
                        int length=lengthoflinkedlist(hptr); // time complexity = O(n)
                        if(nodeposend==length){
                            head* temphptr=hptr;
                            hptr=hptr->next;
                            delete temphptr;
                            return hptr;
                        }
                        head* temphptr=hptr;
                        int nodeposstart=length-nodeposend;
                        head* prevelement=NULL;
                        while(temphptr){ // time complexity = O(n)
                            if(nodeposstart==0){
                                prevelement->next=temphptr->next;
                                delete(temphptr);
                                break;
                            }
                            prevelement=temphptr;
                            nodeposstart--;
                            temphptr=temphptr->next;
                        }
                        return hptr;
                    }
                // optimal sol
                    head* removenodelast2(head* hptr, int nodeposend){
                        if(hptr==NULL) return hptr;
                        head* fast=hptr;
                        for(int i=0;i<nodeposend;i++) fast=fast->next; // time complexity = O(nodeposition)
                        if(fast==NULL){ // nodeposend=length of list
                            head* temphptr=hptr;
                            hptr=hptr->next;
                            delete temphptr;
                            return hptr;
                        }
                        head* slow=hptr;
                        while(fast->next){ // time complexity = O(n-nodeposition)
                            slow=slow->next;
                            fast=fast->next;
                        }
                        head* deletenode=slow->next;
                        slow->next=deletenode->next;
                        delete deletenode;
                        return hptr;
                    }
            // 9. remove middle node from the list
                // brute force sol
                    head* removemidnode1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL){
                            delete hptr;
                            return NULL;
                        }
                        int length=lengthoflinkedlist(hptr); // time complexity = O(n)
                        int beforemidpos=length/2;
                        head* temphptr=hptr;
                        head* prevelement=NULL;
                        while(beforemidpos>0){ // time complexity = O(n/2)
                            prevelement=temphptr;
                            temphptr=temphptr->next;
                            beforemidpos--;
                        }
                        head* deletenode=temphptr;
                        prevelement->next=deletenode->next;
                        delete deletenode;
                        return hptr;
                    }
                // optimal sol 1
                    head* removemidnode2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL){
                            delete hptr;
                            return NULL;
                        }
                        head* fast=hptr;
                        head* slow=hptr;
                        head* prevelement=NULL;
                        while(fast!=NULL && fast->next!=NULL){ // time complexity = O(n/2)
                            slow=slow->next;
                            fast=fast->next->next;
                        }
                        head* deletenode=slow;
                        slow=hptr;
                        while(slow!=deletenode){ // time complexity = O(n/2)
                            prevelement=slow;
                            slow=slow->next; 
                        }
                        prevelement->next=deletenode->next;
                        delete deletenode;
                        return hptr;
                    }
                // optimal sol 2
                    head* removemidnode3(head* hptr){
                        if(hptr==NULL || hptr->next==NULL){
                            delete hptr;
                            return NULL;
                        }
                        head* slow=hptr;
                        head* fast=hptr->next->next;
                        while(fast!=NULL && fast->next!=NULL){ // time complexity = O(n/2)
                            slow=slow->next;
                            fast=fast->next->next;
                        }
                        head* midnode=slow->next;
                        slow->next=midnode->next;
                        delete midnode;
                        return hptr;
                    }
            // 10. merge two sorted lists
                // brute force sol 
                    head* mergetwosortedlists1(head* hptr1, head* hptr2){
                        if(hptr1==NULL) return hptr2;
                        if(hptr2==NULL) return hptr1;
                        vector <int> arr; // space complexity = O(n1+n2)
                        head* temphptr1=hptr1;
                        while(temphptr1){ // time complexity = O(n1)
                            arr.push_back(temphptr1->data);
                            temphptr1=temphptr1->next;
                        }
                        head* temphptr2=hptr2;
                        while(temphptr2){ // time complexity = O(n2)
                            arr.push_back(temphptr2->data);
                            temphptr2=temphptr2->next;
                        }
                        div(arr,0,arr.size()-1); // time complexity = O((n1+n2)*log(n1+n2))
                        head* newhead=new head(arr[0]); // space complexity = O(n1+n2)
                        head* tempnewhead=newhead;
                        for(int i=1;i<arr.size();i++){ // time complexity = O(n1+n2)
                            head* node=new head(arr[i]);
                            tempnewhead->next=node;
                            tempnewhead=node;
                        }
                        return newhead;
                    }
                // optimal sol
                    head* mergetwosortedlists2(head* hptr1, head* hptr2){
                        if(hptr1==NULL) return hptr2;
                        if(hptr2==NULL) return hptr1;
                        head* temphptr1=hptr1;
                        head* temphptr2=hptr2;
                        head* node=new head(-1);
                        head* tempnode=node;
                        while(temphptr1!=NULL && temphptr2!=NULL){ // time complexity = O(n1+n2)
                            if(temphptr1->data <= temphptr2->data){
                                tempnode->next=temphptr1;
                                temphptr1=temphptr1->next;
                            }
                            else{
                                tempnode->next=temphptr2;
                                temphptr2=temphptr2->next;
                            }
                            tempnode=tempnode->next;
                        }
                        if(temphptr1) tempnode->next=temphptr1;
                        else tempnode->next=temphptr2;
                        return node->next;
                    }
            // 11. sort the list
                // brute force sol
                    head* sortlist1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        vector <int> arr; // space complexity = O(n)
                        head* temphptr=hptr;
                        while(temphptr){ // time complexity = O(n)
                            arr.push_back(temphptr->data);
                            temphptr=temphptr->next;
                        }
                        div(arr,0,arr.size()-1); // time complexity = O(nlogn)
                        temphptr=hptr;
                        int i=0;
                        while(temphptr){ // time complexity = O(n)
                            temphptr->data=arr[i];
                            i++;
                            temphptr=temphptr->next;
                        }
                        return hptr;
                    }
                // optimal sol using merge sort algorithm
                    head* midtomergesortlist2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        head* slow=hptr;
                        head* fast=hptr->next;
                        while(fast!=NULL && fast->next!=NULL){
                            slow=slow->next;
                            fast=fast->next->next;
                        }
                        return slow;
                    }
                    head* sortlist2merge(head* left, head* right){
                        head* samplenode=new head(-1);
                        head* tempsamplenode=samplenode;
                        while(left!=NULL && right!=NULL){
                            if(left->data < right->data){
                                tempsamplenode->next=left;
                                left=left->next;
                            }
                            else{
                                tempsamplenode->next=right;
                                right=right->next;
                            }
                            tempsamplenode=tempsamplenode->next;
                        }
                        if(left) tempsamplenode->next=left;
                        else tempsamplenode->next=right;
                        return samplenode->next;
                    }
                    head* sortlist2divide(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        // find mid
                        head* mid=midtomergesortlist2(hptr); // time complexity = O(n/2)
                        head* lefthead=hptr;
                        head* righthead=mid->next;
                        mid->next=NULL;
                        // dividing the list => time complexity = O(logn)
                        head* leftsortedhead=sortlist2divide(lefthead);
                        head* rightsortedhead=sortlist2divide(righthead);
                        // merge the divided list => time complexity = O(n)
                        head* newhead=sortlist2merge(leftsortedhead, rightsortedhead);
                        return newhead;
                    }
            // 12. sort list containing 0s, 1s, and 2s
                // brute force sol
                    head* sortlistof012_1(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        head* temphptr=hptr;
                        int cnt0=0;
                        int cnt1=0;
                        int cnt2=0;
                        while(temphptr){ // time complexity = O(n)
                            if(temphptr->data == 0) cnt0++;
                            else if(temphptr->data == 1) cnt1++;
                            else cnt2++;
                            temphptr=temphptr->next;
                        }
                        temphptr=hptr;
                        while(temphptr){ // time complexity = O(n)
                            if(cnt0){
                                temphptr->data = 0;
                                cnt0--;
                            }
                            else if(cnt1){
                                temphptr->data = 1;
                                cnt1--;
                            }
                            else{
                                temphptr->data = 2;
                                cnt2--;
                            }
                            temphptr=temphptr->next;
                        }
                        return hptr;
                    }
                // optimal sol
                    head* sortlistof012_2(head* hptr){
                        if(hptr==NULL || hptr->next==NULL) return hptr;
                        head* list0=new head(-1);
                        head* temp0=list0;
                        head* list1=new head(-1);
                        head* temp1=list1;
                        head* list2=new head(-1);
                        head* temp2=list2;
                        head* temphptr=hptr;
                        while(temphptr){ // time complexity = O(n)
                            if(temphptr->data == 0){
                                temp0->next=temphptr;
                                temp0=temphptr;
                            }
                            else if(temphptr->data == 1){
                                temp1->next=temphptr;
                                temp1=temphptr;
                            }
                            else{
                                temp2->next=temphptr;
                                temp2=temphptr;
                            }
                            temphptr=temphptr->next;
                        }
                        if(list1->next) temp0->next=list1->next;
                        else temp0->next=list2->next;
                        temp1->next=list2->next;
                        temp2->next=NULL;
                        head* newhead=list0->next;
                        delete(list0);
                        delete(list1);
                        delete(list2);
                        return newhead;
                    }
            // 13. find intersection point of Y list
                void createYlist(head* head1, head* head2, head* commonhead){
                    if(head1==NULL && head2==NULL) return;
                    if(head1==NULL){
                        head* temphead2=head2;
                        while(temphead2->next) temphead2=temphead2->next;
                        temphead2->next=commonhead;
                        return;
                    }
                    if(head2==NULL){
                        head* temphead1=head1;
                        while(temphead1->next) temphead1=temphead1->next;
                        temphead1->next=commonhead;
                        return;
                    }
                    head* temphead1=head1;
                    head* temphead2=head2;
                    while(temphead1->next) temphead1=temphead1->next; 
                    temphead1->next=commonhead;
                    while(temphead2->next) temphead2=temphead2->next;
                    temphead2->next=commonhead;
                }
                    // brute force sol
                        head* intersectionnodeofYlist1(head* hptr1, head* hptr2){
                            if(hptr1==NULL || hptr2==NULL) return NULL;
                            head* temphptr1=hptr1;
                            while(temphptr1){ // time complexity = O(n1)
                                head* temphptr2=hptr2;
                                while(temphptr2){ // time complexity = O(n2)
                                    if(temphptr1 == temphptr2) return temphptr1;
                                    temphptr2=temphptr2->next;
                                }
                                temphptr1=temphptr1->next;
                            }
                            return NULL;
                        }
                    // better sol 1
                        head* intersectionnodeofYlist2(head* hptr1, head* hptr2){
                            if(hptr1==NULL || hptr2==NULL) return NULL;
                            map <head*,int> hash; // space complexity = O(n1)
                            head* temphptr1=hptr1;
                            while(temphptr1){ // time complexity = O(n1)
                                hash[temphptr1]++; // time complexity = O(logn1)
                                temphptr1=temphptr1->next;
                            }
                            head* temphptr2=hptr2;
                            while(temphptr2){ // time complexity = O(n2) 
                                if(hash.find(temphptr2) != hash.end()) return temphptr2; // time complexity = O(logn1)
                                temphptr2=temphptr2->next;
                            }
                            return NULL;
                        }
                    // better sol 2
                        head* intersectionnodeofYlist3(head* hptr1, head* hptr2){
                            if(hptr1==NULL || hptr2==NULL) return NULL;
                            // find lengths
                            int length1=lengthoflinkedlist(hptr1); // time complexity = O(n1)
                            int length2=lengthoflinkedlist(hptr2); // time complexity = O(n2)
                            int diff=length1-length2;
                            head* temphptr1=hptr1;
                            head* temphptr2=hptr2;
                            int cnt=0;
                            while(cnt != diff){ // time complexity = O(abs(n1-n2))
                                if(diff < 0){ // length2 > length1
                                    temphptr2=temphptr2->next;
                                    cnt--;
                                }
                                if(diff > 0){ // length1 > length2
                                    temphptr1=temphptr1->next;
                                    cnt++;
                                }
                            }
                            while(temphptr1!=NULL && temphptr2!=NULL){ // time complexity = O(min(n1,n2))
                                if(temphptr1 == temphptr2) return temphptr1;
                                temphptr1=temphptr1->next;
                                temphptr2=temphptr2->next;
                            }
                            return NULL;
                        }
                    // optimal sol
                        head* intersectionnodeofYlist4(head* hptr1, head* hptr2){
                            if(hptr1==NULL || hptr2==NULL) return NULL;
                            head* temphptr1=hptr1;
                            head* temphptr2=hptr2;
                            while(temphptr1 != temphptr2){ // time complexity = O(n1+n2)
                                temphptr1=temphptr1->next;
                                temphptr2=temphptr2->next;
                                if(temphptr1==temphptr2) return temphptr1;
                                if(temphptr1==NULL) temphptr1=hptr2;
                                if(temphptr2==NULL) temphptr2=hptr1;
                            }
                            return temphptr1;
                        }
                // 14. add 1 to data represented by list
                    // brute force sol
                        head* add1tolistconcatdata_1(head* hptr){
                            if(hptr==NULL) return NULL;
                            head* temphptr=hptr;
                            // reverse list
                            head* prevelement=NULL;
                            while(temphptr){ // time complexity = O(n)
                                head* nextelement=temphptr->next;
                                temphptr->next=prevelement;
                                prevelement=temphptr;
                                temphptr=nextelement;
                            }
                            head* newhead=prevelement;
                            // add 1
                            head* carry=new head(1);
                            head* tempnewhead=newhead;
                            while(tempnewhead){ // time complexity = O(n)
                                tempnewhead->data=tempnewhead->data+carry->data;
                                if(tempnewhead->data == 10){
                                    tempnewhead->data=0;
                                    carry->data=1;
                                }
                                else{
                                    carry->data=0;
                                    break;
                                }
                                tempnewhead=tempnewhead->next;
                            }
                            // reverse back the list
                            tempnewhead=newhead;
                            prevelement=NULL;
                            while(tempnewhead){ // time complexity = O(n)
                                head* nextelement=tempnewhead->next;
                                tempnewhead->next=prevelement;
                                prevelement=tempnewhead;
                                tempnewhead=nextelement;
                            }
                            hptr=prevelement; // head of the reverse of ans list
                            if(carry->data){
                                carry->next=hptr;
                                hptr=carry;
                            }
                            return hptr;
                        }
                    // optimal sol
                        head* add1tolistconcatdata_2(head* hptr){
                            if(hptr==NULL) return NULL;
                            
                        }

    // double linked list
        struct nodedll{
            int data;
            nodedll* next;
            nodedll* prev;
            nodedll(int data1, nodedll* prev1, nodedll* next1){
                data=data1;
                prev=prev1;
                next=next1;
            }
        };
        class Nodedll{
            public: 
                int data;
                Nodedll* prev;
                Nodedll* next;
                Nodedll(int data1, Nodedll* prev1, Nodedll* next1){
                    data=data1;
                    prev=prev1;
                    next=next1;
                }
        };
        // convert array to doubly linked list
            class headdll{
                public:
                    int data;
                    headdll* prev;
                    headdll* next;
                    headdll(int data1, headdll* prev1, headdll* next1){
                        data=data1;
                        prev=prev1;
                        next=next1;
                    }
                    headdll(int data1, headdll* next1) : data(data1), prev(nullptr), next(next1){}
                    headdll(int data1) : data(data1), prev(nullptr), next(nullptr){}
            };
            headdll* arrtodll(vector <int> &arr){
                int size=arr.size();
                headdll* headptr=new headdll(arr[0]);
                headdll* tempheadptr=headptr;
                for(int i=1;i<size;i++){
                    headdll* node=new headdll(arr[i],tempheadptr,NULL);
                    tempheadptr->next=node;
                    tempheadptr=node;
                }
                return headptr;
            }
       // traversal exactly same as single linked list
            void printdll(headdll* headptr){
                if(headptr == NULL) return;
                while(headptr){
                    cout<<headptr->data<<" ";
                    headptr=headptr->next;
                }
            }
        // length exactly same as single linked list
            int lengthofdll(headdll* hptr){
                int length=0;
                headdll* temphptr=hptr;
                while(temphptr){
                    length++;
                    temphptr=temphptr->next;
                }
                return length;
            }
        // search an element is also exactly same as single linked list
        // deletion
            // 1. head
                headdll* deleteheaddll(headdll* hptr){
                    if(hptr == nullptr) return hptr;
                    headdll* newhead=hptr->next; // if the linked list was only had head then newhead=null after deleting the head
                    delete hptr;
                    if(newhead != NULL) newhead->prev=NULL;
                    return newhead;
                }
            // 2. tail
                headdll* deletetaildll(headdll* hptr){
                    if(hptr == NULL) return hptr;
                    if(hptr->next == NULL){
                        delete hptr;
                        return NULL;
                    }
                    else{
                        headdll* temphptr=hptr;
                        while(temphptr->next) temphptr=temphptr->next;
                        temphptr->prev->next=NULL;
                        delete temphptr;
                    }
                    return hptr;
                }
            // 3. position
                headdll* deletepositiondll(headdll* hptr, int pos){
                    headdll* temphptr=hptr;
                    int length=lengthofdll(hptr);
                    if(hptr==NULL) return hptr;
                    else if(pos<1 || pos>length){
                        cout<<"Position is out of boundaries, hence deletion cannot be done!!"<<endl;
                        return hptr;
                    }
                    else if(pos==1){
                        headdll* newhptr=hptr->next;
                        delete hptr;
                        if(newhptr != NULL) newhptr->prev=NULL;
                        return newhptr;
                    }
                    else if(pos==length){
                        while(temphptr->next) temphptr=temphptr->next;
                        temphptr->prev->next=NULL;
                        delete temphptr;
                        return hptr;
                    }
                    else{
                        int cnt=0;
                        while(temphptr){
                            cnt++;
                            if(cnt == pos){
                                temphptr->prev->next=temphptr->next;
                                temphptr->next->prev=temphptr->prev;
                                delete temphptr;
                                break;
                            }
                            temphptr=temphptr->next;
                        }
                    }
                    return hptr;
                }
            // 4. value
                headdll* deleteelementdll(headdll* hptr, int val){
                    headdll* temphptr=hptr;
                    if(hptr==NULL) return hptr;
                    else if(hptr->data == val && hptr->next==NULL){
                        delete hptr;
                        return NULL;
                    }
                    else if(hptr->data == val){
                        headdll* newhead=hptr->next;
                        newhead->prev=NULL;
                        delete hptr;
                        return newhead;
                    }
                    else{
                        while(temphptr){
                            if(temphptr->data==val && temphptr->next==NULL){
                                temphptr->prev->next=NULL;
                                delete temphptr;
                                break;
                            }
                            else if(temphptr->data == val){
                                temphptr->prev->next=temphptr->next;
                                temphptr->next->prev=temphptr->prev;
                                delete temphptr;
                                break;
                            }
                            temphptr=temphptr->next;
                        }
                    }
                    return hptr;
                }
        // insertion
            // 1. head
                headdll* insertheaddll(headdll* hptr, int val){
                    headdll* newhead=new headdll(val);
                    if(hptr==NULL) return newhead;
                    newhead->prev=nullptr; // unnecessary as the constructor automatically do this but no error to write it
                    newhead->next=hptr;
                    hptr->prev=newhead;
                    return newhead;
                }
            // 2. tail
                headdll* inserttaildll(headdll* hptr, int val){
                    headdll* newnode=new headdll(val);
                    if(hptr==NULL) return newnode;
                    headdll* temphptr=hptr;
                    while(temphptr->next) temphptr=temphptr->next;
                    temphptr->next=newnode;
                    newnode->prev=temphptr;
                    return hptr;
                }
            // 3. position
                headdll* insertpositiondll(headdll* hptr, int pos, int val){
                    headdll* newnode=new headdll(val);
                    int length=lengthofdll(hptr);
                    headdll* temphptr=hptr;
                    if(hptr==NULL && pos==1) return newnode;
                    if(pos==1){
                        newnode->next=hptr;
                        hptr->prev=newnode;
                        return newnode;
                    }
                    if(pos==length+1){
                        while(temphptr->next) temphptr=temphptr->next;
                        temphptr->next=newnode;
                        newnode->prev=temphptr;
                        return hptr;
                    }
                    if(pos<1 || pos>length+1){
                        cout<<"Position is out of boundaries, hence insertion fails!!"<<endl;
                        return hptr;
                    }
                    int cnt=0;
                    while(temphptr){
                        cnt++;
                        if(cnt == pos) break;
                        temphptr=temphptr->next;
                    }
                    headdll* prevelement=temphptr->prev;
                    prevelement->next=newnode;
                    newnode->prev=prevelement;
                    newnode->next=temphptr;
                    temphptr->prev=newnode;
                    return hptr;
                }
            // 4. value
                headdll* insertatotherelementplacedll(headdll* hptr, int element, int val){
                    headdll* newnode=new headdll(val);
                    if(hptr==NULL){
                        cout<<"Empty linked list so cannot find the element to replace, hence insertion fails!!";
                        cout<<endl;
                        return NULL;
                    }
                    if(hptr->data == element){
                        hptr->prev=newnode;
                        newnode->next=hptr;
                        return newnode;
                    }
                    headdll* temphptr=hptr;
                    bool found=false;
                    while(temphptr){
                        if(temphptr->data == element){
                            found=true;
                            break;
                        }
                        temphptr=temphptr->next;
                    }
                    if(!found){
                        cout<<"Element not found, so insertion fails!!";
                        return hptr;
                    }
                    headdll* prevelement=temphptr->prev;
                    prevelement->next=newnode;
                    newnode->prev=prevelement;
                    newnode->next=temphptr;
                    temphptr->prev=newnode;
                    return hptr;
                }
        // reverse the doubly linked list
            // brute force sol
                headdll* reversedll1(headdll* hptr){
                if(hptr==NULL || hptr->next==NULL) return hptr;
                else{
                    stack <int> st; // space complexity = O(n)
                    headdll* temphptr=hptr;
                    while(temphptr){ // time complexity = O(n)
                        st.push(temphptr->data); // time complexity = O(1)
                        temphptr=temphptr->next;
                    }
                    temphptr=hptr;
                    while(temphptr){ // time complexity = O(n)
                        swap(temphptr->data, st.top());
                        st.pop(); // time complexity = O(1)
                        temphptr=temphptr->next;
                    }
                }
                return hptr;
            }
            // optimal sol 
                headdll* swaplinks(headdll* temphead){
                    headdll* prevelement=temphead->prev;
                    temphead->prev=temphead->next;
                    temphead->next=prevelement;
                    return prevelement;
                }
                headdll* reversedll2(headdll* hptr){
                    if(hptr==NULL || hptr->next==NULL) return hptr;
                    headdll* temphptr=hptr;
                    headdll* secondlastelement;
                    while(temphptr){ // time complexity = O(n)
                        secondlastelement=swaplinks(temphptr);
                        temphptr=temphptr->prev;
                    }
                    headdll* newhead=secondlastelement->prev;
                    return newhead;
                }

int main(){

    /*string str;
    getline(cin,str);
    cout<<str;*/

    /*int age;
    cout<<"Enter your age: "<<endl;
    cin>>age;
    (age>=18)?cout<<"Adult":cout<<"Not adult"<<endl;*/

    /*int age;
    cout<<"Enter your age: ";
    cin>>age;
    if(age<18){
        cout<<"Not eligible for job"<<endl;
    }
    else if(age<=57){
        cout<<"Eligible for job";
        if(age>=55){
            cout<<", but retirement soon!"<<endl;
        }
    }
    else{
        cout<<"Retirement time";
    }*/

    /*int day;
    cout<<"Enter day number: ";
    cin>>day;
    switch(day){
        case 1:
            cout<<"Monday";
            break;
        case 2:
            cout<<"Tuesday";
            break;
        case 3:
            cout<<"Wednesday";
            break;
        case 4:
            cout<<"Thursday";
            break;
        case 5:
            cout<<"Friday";
            break;
        case 6:
            cout<<"Saturday";
            break;
        case 7:
            cout<<"Sunday";
            break;
        default:
            cout<<"Invalid day number";
        }*/

// functions
    // sum
        /*int num1,num2;
        cout<<"Enter number 1: ";
        cin>>num1;
        cout<<"Enter number 2: ";
        cin>>num2;
        cout<<"Sum: "<<sum(num1,num2);*/
    // Lower_bound();
    // Upper_bound();
    // counting digits
        /*int num;
        cout<<"Enter number: ";
        cin>>num;
        cout<<"Number of digits: "<<count_digits(num)<<endl;*/
    // reversing the number
        /*int num;
        cout<<"Enter the number: ";
        cin>>num;
        reverse_num(num);*/
    // checking the palindrome number
        /*int num;
        cout<<"Enter number: ";
        cin>>num;
        palindrome_num(num);*/
    // checking the armstrong number
        /*int num;
        cout<<"Enter number: ";
        cin>>num;
        armstrong_num(num);*/
    // printing all divisors
        /*int num;
        cout<<"Enter number: ";
        cin>>num;
        div(num);*/
    // prime();
    // gcd();

// solutions 
    // sol 1:
        // cout<<sol1(4)<<" "<<sol1(2)<<" "<<sol1(12)<<endl; // 1 -1 -1
    // sol 2:
        // cout<<sol2(4)<<" "<<sol2(2)<<" "<<sol2(0)<<endl; // 4 -1 -1
    // sol 3:
        // cout<<sol3(4)<<" "<<sol3(2)<<" "<<sol3(1)<<endl; // 1 1 -1
    // sol 4:
        // cout<<sol4(4)<<" "<<sol4(2)<<" "<<sol4(1)<<endl; // 9 -1 4

// patterns
    /* int num;
    cout<<"Enter number: ";
    cin>>num;*/
    // pattern1(num);
    // pattern2(num);
    // pattern3(num);
    // pattern4(num);
    // pattern5(num);
    // pattern6(num);
    // pattern7(num);
    // pattern8(num);
    // pattern9(num);
    // pattern10(num);
    // pattern11(num);
    // pattern12(num);
    // pattern13(num);
    // pattern14(num);
    // pattern15(num);
    // pattern16(num);
    // pattern17(num);
    // pattern18(num);
    // pattern19(num);
    // pattern20(num);
    // pattern21(num);
    // pattern22(num);

// recursion
    // name(1,5);
    // countAscending(1,10);
    // countDescending(1,10);
    // countAscendingByBacktracking(10,10);
    // countDescendingByBacktracking(1,10);
    // sumOfFirst_N_NumbersParameterised(5,0);
    // cout<<"Sum of first 5 numbers: "<<sumOfFirst_N_NumbersFunctional(5);
    // cout<<"Factorial of 5: "<<factorial(5);
    // cout<<fibonacci_num(4);
    /*int a[]={1,2,3,5,4};
    reverseArray2Ptr(a,0,4);
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }*/
    /*int a[]={1,2,3,4,5,6};
    reverseArray1Ptr(a,0);
    for(int i=0;i<6;i++){
        cout<<a[i]<<" ";
    }*/
    /*cout<<palindromeString("Ratan",0);
    cout<<palindromeString("NITIN",0);*/

//utility library
    // Pair();
    // Vector();
    // List();
    // Deque();
    // Stack();
    // Queue();
    // Priority_queue();
    // Set();
    // Multiset();
    // Unordered_set();
    // Map();
    // Multimap();
    // Unordered_map();

//algorithms
    // Sort_array();
    // Sort_vector();
    // Sort_pairArray();
    // builtin_popcount();
    // next_permutation();
    // max_min();

// hashing
    /* pre computation and fetching
    inside main if hash array is declared, the max size can be 10^6 or 1e6 only for the integer arrays and 10^7 or 1e7 for boolean arrays, beyond this it will throw segementation fault error
    if hash array declared globally it can go for 10^7 or 1e7 for integers and 10^8 or 1e8 for boolean arrays
    in global declaration of integer array no need to initialize them as 0 as it takes by default 0 instead of garbage values*/ 
        /*int arr[]={1,2,2,3,3,4,4,4,4,4,5,6,6,6,6,7,7,7,7,7,8,8,8,9,9,9,9,9};
        int len=size(arr);*/
        // numberHashing_hashCountFreq(arr,len);
        // mapHashing_countFreq(arr,len);
        // mapHashing_countHighFreq(arr,len);
        // mapHashing_countLowFreq(arr,len);
        /*string str="taleesharishirajansarianand";
        int len=str.size();*/
        // charHashing_countFreq(str,len);

// sorting
    // int arr[]={10,4,5,2,20,0,13,8,7,17};
    // selection_sort(arr,10);
    // bubble_sort(arr,10);
    // insertion_sort(arr,10);
    // vector <int> arr = {10,4,5,2,20,0,13,8,7,17};
    // div(arr,0,9); // merge sort
    // sort(arr,0,9); // quick sort
    // for(auto i : arr) cout<<i<<" ";

// arrays
    /*1. declared as int/char/string/pair<int,int> arr_name[size];
    2. if declared inside main, array is created with garbage values stored and has max size limit 10^6
    3. if decalred globally that is outside the main, array is created with all the elements as 0 and has maz soze limit as 10^7 
    4. stored in contagious memory location in computer memory where first element position(index 0) is not predicatable but next is (index 1 to size-1) is just one after the another*/
        // easy questions
            // 1. find largest element
                // brute force sol (time complexity = O(nlog2n))
                    /*vector <int> arr = {10,30,4,2,56};
                    int size = arr.size();
                    div(arr,0,size-1);
                    cout<<arr[size-1];*/
                // optimal sol (time complexity = O(n))
                    /*int arr[]={10,30,4,2,56};
                    int largest=arr[0];
                    for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++){
                        if(largest<arr[i]) largest=arr[i];
                    }
                    cout<<largest;*/
            // 2. find second largest element without sorting
                // brute force sol (time complexity = O(nlogn + n) for worst case)
                    /*vector <int> arr = {10,30,4,2,56};
                    div(arr,0,arr.size()); // time complexity = O(nlogn)
                    int largest=arr[arr.size()-1];
                    int sec_largest;
                    for(int i=arr.size()-2;i>=0;i--){ // time complexity = O(n) in worst case
                        if(arr[i]!=largest){
                            sec_largest=arr[i];
                            break;
                        }
                    }
                    cout<<sec_largest;*/
                // better sol (time complexity = O(2n))
                    /*int arr[] = {10,30,4,2,56};
                    int largest = arr[0];
                    for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++){ // time complexity = O(n)
                        if(arr[i]>largest) largest=arr[i];
                    }
                    int sec_largest = -1;
                    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){ // time complexity = O(n)
                        if(arr[i]>sec_largest && arr[i]!=largest) sec_largest=arr[i];
                    }
                    cout<<sec_largest;*/
                // optimal sol (time complexity = O(n))
                    /*int arr[]={10,30,4,2,56};
                    int largest=arr[0], sec_largest=-1;
                    for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++){
                        if(arr[i]>largest){
                            sec_largest=largest;
                            largest=arr[i];
                        }
                        else if(arr[i] != largest && arr[i]>sec_largest) sec_largest=arr[i];
                    }
                    cout<<sec_largest;*/
            // 3. check if array is sorted
                /*int arr[] = {10,30,4,2,56};
                // int arr[]={2,4,10,30,56};
                int flag=0;
                for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++){
                    if(arr[i]<=arr[i-1]) flag++;
                }
                if(flag!=0) cout<<"Unsorted array";
                else cout<<"Sorted array";
                // time complexity = O(n)*/
            // 4. remove duplicates from a sorted array and tell the no of unique elements
                // brute force sol (time complexity = o(nlogn+n), space complexity = O(n) in worst case)
                    /*int arr[] = {2,2,4,4,4,10,10,30,30,56};
                    set <int> s; // space complexity = O(n)
                    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) s.insert(arr[i]); // time complexity = O(logn)
                    int ind=0;
                    for(auto i:s){ // time complexity = O(n)
                        cout<<i<<" ";
                        arr[ind]=i;
                        ind++;
                    }
                    cout<<endl<<ind;*/
                // optimal sol (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={2,2,4,4,4,10,10,30,30,56};
                    int i=0;
                    for(int j=1;j<sizeof(arr)/sizeof(arr[0]);j++){ // time complexity = O(n)
                        if(arr[i]!=arr[j]){
                            arr[i+1]=arr[j];
                            i++;
                        }
                    }
                    for(int k=0;k<=i;k++) cout<<arr[k]<<" ";
                    cout<<endl<<i+1;*/
            // 5. left rotate the array by one place
                // optimal sol (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={2,2,4,4,4,10,10,30,30,56};
                    int temp=arr[0];
                    for(int i=1;i<sizeof(arr)/sizeof(arr[0]);i++) arr[i-1]=arr[i];
                    arr[sizeof(arr)/sizeof(arr[0])-1]=temp;
                    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++) cout<<arr[i]<<" ";*/
            // 6. left rotate the array by n places
                // brute force sol (time complexity = O(n+rotation), space complexity = O(rotation))
                    /*int n,j=0;
                    int arr[]={2,2,4,4,4,10,10,30,30,56};
                    int len=sizeof(arr)/sizeof(arr[0]);
                    cout<<"Enter how many places to left shift in array: ";
                    cin>>n;
                    n=n%len;
                    int temp[n]; // space complexity = O(rotation)
                    for(int i=0;i<n;i++) temp[i]=arr[i]; // time complexity = O(rotation)
                    for(int i=n;i<len;i++) arr[i-n]=arr[i]; // time complexity = O(n-rotation)
                    for(int i=len-n;i<len;i++){ // time complexity = O(rotation)
                        arr[i]=temp[j]; // or arr[i]=temp[i-(len-n)];
                        j++;
                    }
                    for(int i=0;i<len;i++) cout<<arr[i]<<" ";*/
                // optimal sol (time complexity = O(2n), space complexity = o(1))
                    /*int arr[]={2,2,4,4,4,10,10,30,30,56};
                    int len=sizeof(arr)/sizeof(arr[0]);
                    int n;
                    cout<<"Enter how many places to left shift in array: ";
                    cin>>n;
                    // in c++ we have STL so we dont need any manual reverse func but the actual func can be given below;
                    // void reverse(int arr[],start,end){
                    //     while(start<=end){
                    //         int temp=arr[start];
                    //         arr[start]=arr[end];
                    //         arr[end]=temp;
                    //         start++;
                    //         end--;
                    //     }
                    // };
                    reverse(arr,arr+n); // time complexity = O(rotation)
                    reverse(arr+n,arr+len); // time complexity = O(n-rotation)
                    reverse(arr,arr+len); // time complexity = O(n)
                    for(int i=0;i<len;i++) cout<<arr[i]<<" ";*/
            // 7. move all 0s to the end
                // brute force sol (time complexity = O(2n), space complexity = O(n))
                    /*int arr[]={2,2,0,4,4,0,4,10,0,0,10,30,0,30,0,56,0,0};
                    int len=sizeof(arr)/sizeof(arr[0]);
                    vector <int> temp; // space complexity = O(n) in worst case
                    for(int i=0;i<len;i++){ // time complexity = O(n)
                        if(arr[i]!=0) temp.push_back(arr[i]);
                    }
                    for(int i=0;i<temp.size();i++) arr[i]=temp[i]; // time complexity = O(no of non-zero elements)
                    for(int i=temp.size();i<len;i++) arr[i]=0; // time complexity = O(n-no of non-zero elements)
                    for(int i=0;i<len;i++) cout<<arr[i]<<" ";*/
                // optimal sol (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={2,2,0,4,4,0,4,10,0,0,10,30,0,30,0,56,0,0};
                    // int arr[]={10,20,30,40,50};
                    int len=sizeof(arr)/sizeof(arr[0]);
                    int j=-1;
                    for(int i=0;i<len;i++){ // time complexity = O(x), x is the first iteration to find 0 in the array
                        if(arr[i]==0){
                            j=i;
                            break;
                        }
                    }
                    if(j!=-1){
                        for(int i=j+1;i<len;i++){ // time complexity = (len-x)
                            if(arr[i]!=0){
                                swap(arr[i],arr[j]);
                                j++;
                            }
                        }
                    }
                    for(int i=0;i<len;i++) cout<<arr[i]<<" ";*/
            // 8. linear search (time complexity = O(n))
                /*int arr[]={2,2,4,4,4,10,10,30,30,56};
                int num,count=-1;
                cout<<"Enter number to linear search: ";
                cin>>num;
                for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){ // time complexity = O(n)
                    if(arr[i]==num){ // gives first occurence
                        count=i;
                        break;
                    }
                    // if(arr[i]==num) count=i; // gives last occurence
                }
                if(count==-1) cout<<"Element not found";
                else cout<<"Element found at: "<<count;*/
            // 9. union and intersection of two sorted arrays
                /*int arr1[]={2,2,3,4,4,4,6,10,10,30,30,40,45,55,56};
                int len1=sizeof(arr1)/sizeof(arr1[0]);
                int arr2[]={3,3,5,5,5,5,6,6,7,8,8,9,10,10,25,30,30,30};
                int len2=sizeof(arr2)/sizeof(arr2[0]);*/
                    // union [sum of both arrays without duplicates i.e., [2,3,4,5,6,7,8,9,10,25,30,40,45,55,56]]
                        // brute force sol (time complexity = O(n1logn + n2logn) + O(n1+n2), space complexity = O(n1+n2) + O(n1+n2))
                            /*set <int> temp; // space complexity = O(n1+n2)
                            for(int i=0;i<len1;i++) temp.insert(arr1[i]); // time complexity = O(n1logn), n is size of set
                            for(int i=0;i<len2;i++) temp.insert(arr2[i]); // time complexity = O(n2logn), n is size of set
                            vector <int> Union; // space complexity = O(n1+n2)  just to return the answer not using to solve the question
                            for(auto element:temp) Union.push_back(element); // time complexity = O(n1+n2)
                            for(auto i:Union) cout<<i<<" ";*/
                        // optimal sol (time complexity = O(n1+n2), space complexity = O(n1+n2))
                            /*int i=0,j=0;
                            vector <int> Union; // space complexity = O(n1+n2) in worst case and only for showing the output or return the answer
                            while(i<len1 && j<len2){ // time complexity = O(n1+n2)
                                if(arr1[i]<=arr2[j]){
                                    if(Union.size()==0 || Union.back() != arr1[i]){
                                        Union.push_back(arr1[i]); // Union.back() gives last inserted element in vector and is necessary to have element in vector to compare it with other element so Union.size()==0 must be there to insert the first element in the Union vector
                                    }
                                    i++;
                                }
                                else{
                                    if(Union.size()==0 || Union.back() != arr2[j]){
                                        Union.push_back(arr2[j]);
                                    }
                                    j++;
                                }
                            }
                            while(i<len1){
                                if(Union.size()==0 || Union.back() != arr1[i])Union.push_back(arr1[i]);
                                i++;
                            }
                            while(j<len2){
                                if(Union.size()==0 || Union.back() != arr2[j])Union.push_back(arr2[j]);
                                j++;
                            }
                            for(auto i : Union) cout<<i<<" ";*/
                    // intersection [common elements of both the arrays i.e., [3,6,10,10,30,30] and duplicates are allowed but with minimal common]
                        // brute force sol (time complexity = O(n1*n2), space complexity = O(size of smallest arrays))
                            /*int vis[len1]={0};
                            vector <int> intersec;
                            for(int i=0;i<len2;i++){
                                for(int j=0;j<len1;j++){
                                    if(arr2[i]==arr1[j] && vis[j]==0){
                                        intersec.push_back(arr2[i]);
                                        vis[j]=1;
                                        break;
                                    }
                                    if(arr1[j]>arr2[i])break;
                                }
                            }
                            for(auto i : intersec)cout<<i<<" ";*/
                        // optimal sol (time complexity = O(n1+n2) in worst case, space complexity = O(n1+n2) in worst case to return the answer)
                            /*int i=0,j=0;
                            vector <int> intersec; // space complexity = O(n1+n2)
                            while(i<len1 && j<len2){ // time complexity = O(n1+n2)
                                if(arr1[i]<arr2[j])i++;
                                else if(arr2[j]<arr1[i])j++;
                                else{
                                    intersec.push_back(arr1[i]);
                                    i++;
                                    j++;
                                }
                            }
                            for(auto i : intersec)cout<<i<<" ";*/
            // 10. find missing number in array size=n elements are 1 to n eg, [1,2,4,5] n=5 elements=1 to 5 missing=3
                // brute force sol (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={1,2,4,5};
                    int size=5;
                    for(int i=1;i<=size;i++){ // time complexity = O(n)
                        int flag=0;
                        for(int j=0;j<size-1;j++){ // j<size-1 coz array has missing a value, time complexity = O(n)
                            if(i==arr[j]){
                                flag++;
                                break;
                            }
                        }
                        if(flag==0)cout<<"Missing: "<<i;
                    }*/
                // better sol (time complexity = O(2n), space complexity = O(n))
                    /*int arr[]={1,2,4,5};
                    int size=5;
                    int hash[size+1]={0}; // space complexity = O(n)
                    for(int i=0;i<size-1;i++) hash[arr[i]]=1; // time complexity = O(n)
                    for(int i=1;i<size;i++){ // time complexity = O(n)
                        if(hash[i]==0) cout<<"Missing: "<<i; 
                    }*/
                // optimal sol1 (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={1,2,4,5};
                    int size=5,sum=(size*(size+1))/2,arrsum=0;
                    for(int i=0;i<size-1;i++)arrsum += arr[i]; // time complexity = O(n)
                    if(sum != arrsum) cout<<"Missing: "<<sum-arrsum;*/
                // optimal sol2 (time complexity = O(2n) or O(n), space complexity = O(1))
                    /*xor1=1^2^3^4^5 -- just assume
                    xor2=1^2^4^5 -- array elements
                    xor1 ^ xor2 = missing number*/
                        /*int arr[]={1,2,4,5};
                        int size=5;
                        int xor1=0;
                        for(int i=1;i<=size;i++) xor1 ^= i; // time complexity = O(n)
                        int xor2=0;
                        for(int i=0;i<size-1;i++) xor2 ^= arr[i]; // time complexity = O(n)
                        int missing=xor1^xor2;
                        if(missing != 0) cout<<"Missing: "<<missing;*/
                                            // or
                        // time complexity = O(n), space complexity = O(1)
                        /*int arr[]={1,2,4,5};
                        int size=5,xor1=0,xor2=0;
                        for(int i=0;i<size-1;i++){ // time complexity = O(n)
                            xor2 ^= arr[i];
                            xor1 ^= i+1; // xor1=1^2^3^4
                        }
                        xor1 ^= size; // xor1=4^5
                        int missing=xor1^xor2;
                        if(missing != 0) cout<<"Missing: "<<missing;*/
            // 11. maximum consecutive ones eg, [1,1,0,1,1,1,0,0,1,1] = 3
                // optimal sol (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={1,1,0,1,1,1,0,0,1,1};
                    int maxi=0,count=0;
                    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
                        if(arr[i]==1){
                            count++;
                            maxi=max(maxi,count);
                        }
                        else count=0;
                    } 
                    cout<<maxi;*/
            // 12. find the number that appears once and other twice eg, [1,1,2,3,3,4,4] = 2
                // brute force sol (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={1,1,2,3,3,4,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    for(int i=0;i<size;i++){
                        int count=0;
                        for(int j=0;j<size;j++){
                            if(arr[j]==arr[i])count++;
                        }
                        if(count==1)cout<<arr[i];
                    }*/
                // better sol1 hashing (time complexity = O(3n), space complexity = O(n))
                    /*int arr[]={1,1,2,3,3,4,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int maxel=0;
                    for(int i=0;i<size;i++)maxel=max(maxel,arr[i]); // time complexity = O(n)
                    int hash[maxel+1]={0}; // space complexity = O(largest element + 1)
                    for(int i=0;i<size;i++)hash[arr[i]]++; // time complexity = O(n)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(hash[arr[i]]==1)cout<<arr[i];
                    }
                    // hashing can not be done everytime especially when array has negatives or very larhe numbers like 10^12,10^9,etc*/
                // better sol2 map data structure with a large storage datatype for key (time complexity = O(nlogm + (n/2)+1), space complexity = O((n/2)+1))
                    /*int arr[]={1,1,2,3,3,4,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    map<long long,int>m; // space complexity = O((n/2)+1)
                    for(int i=0;i<size;i++)m[arr[i]]++; // time complexity = O(nlogm) where m is size of map i.e.,(n/2)+1
                    for(auto i : m){ // time complexity = O((n/2)+1)
                        if(i.second==1)cout<<i.first;
                    }*/
                // optimal sol (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={1,1,2,3,3,4,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int xorr=0;
                    for(int i=0;i<size;i++)xorr ^= arr[i]; // time complexity = O(n)
                    if(xorr != 0)cout<<xorr;*/
            // 13. find the longest subarray(contigous part of an array) of given sum in a positive elements array eg, [1,2,3,1,1,1,1,4,2,3] sum=3 => [1,1,1] length=3
                // brute force sol1 (time complexity = O(n^3) approx, space complexity = O(1))
                    /*int arr[]={1,2,3,1,1,1,1,4,2,3};
                    int len=0, size=sizeof(arr)/sizeof(arr[0]), sum;
                    cout<<"Enter sum: ";
                    cin>>sum;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            int s=0;
                            for(int k=i;k<=j;k++) s+=arr[k]; // time complexity = O(n)
                            if(sum==s)len=max(len,j-i+1);
                        }
                    }
                    cout<<len;*/
                // brute force sol2 (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={1,2,3,1,1,1,1,4,2,3};
                    int len=0, size=sizeof(arr)/sizeof(arr[0]), sum;
                    cout<<"Enter sum: ";
                    cin>>sum;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        int s=0;
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            s+=arr[j];
                            if(sum==s) len=max(len,j-i+1);
                        }
                    }
                    cout<<len;*/
                // better sol using hashing (time complexity = O(nlogn)for ordered map, O(n*1)for unordered map if no collision, O(n*n)for unordered map if collision occured i.e, worst case, space complexity = O(n))
                    /*int arr[]={1,2,3,1,1,1,1,4,2,3};
                    int arr[]={1,2,-1,3,1,1,0,0,1,1,4,2,3};
                    int maxlen=0, size=sizeof(arr)/sizeof(arr[0]), sum;
                    cout<<"Enter sum: ";
                    cin>>sum;
                    map<int,int> presum; // space complexity = O(n)
                    int s=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        s += arr[i];
                        presum.emplace(s,i);
                        if(sum==s) maxlen=max(maxlen,i+1);
                        int rem=s-sum;
                        if(presum.find(rem) != presum.end()){
                            int len = i-presum[rem];
                            maxlen=max(maxlen,len);
                        }
                        // presum[s] = i; // (works only for +ve integers not the array containing 0)
                        if(presum.find(s) == presum.end()) presum[s] = i; // (also for arrays having 0 and in this case it is the optimal solution)
                    }
                    cout<<maxlen;*/
                // optimal sol (time complexity = O(2n) in worst case, space complexity = O(1))
                    /*int arr[]={1,2,3,1,1,1,1,4,2,3};
                    int maxlen=0, size=sizeof(arr)/sizeof(arr[0]), sum;
                    cout<<"Enter sum: ";
                    cin>>sum;
                    int left=0,right=0,s=arr[0];
                    while(right<size){ // time complexity = O(n)
                        while(left<=right && s>sum){ // time complexity = O(n)
                            s -= arr[left];
                            left++;
                        }
                        if(s==sum) maxlen=max(maxlen,right-left+1);
                        right++;
                        if(right<size) s += arr[right];
                    }
                    cout<<maxlen;*/
        // medium questions
            // 1. two sum eg, [2,6,5,8,11] target=14 => yes it is possible at [1,3] i.e, return indices too
                // brute force sol (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={2,6,5,8,11};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int target,count=0;
                    cout<<"Enter target value: ";
                    cin>>target;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i+1;j<size;j++){ // time complexity = O(n)
                            if(arr[i]+arr[j]==target){
                                cout<<"Yes it is possible at ["<<i<<','<<j<<']';
                                count++;
                                break;
                            }
                        }
                    }
                    if(count==0)cout<<"No it is not possible";*/
                // better sol (time complexity = O(nlogn), space complexity = O(n))
                    /*int arr[]={2,6,5,8,11};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int target,count=0;
                    cout<<"Enter target value: ";
                    cin>>target;
                    map<int,int>hash; // space complexity = O(n)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        int sec=target-arr[i];
                        if(hash.find(sec) != hash.end()){ // time complexity = O(logn)
                            cout<<"Yes it is possible at ["<<hash[sec]<<','<<i<<']';
                            count++;
                            break;
                        }
                        hash[arr[i]]=i;
                    }
                    if(count==0) cout<<"No it is not possible";*/
                // optimal sol (time complexity = O(n)+O(nlogn), space complexity = O(1))
                    /* it is not optimal for returning the indices of the elements of array as for that we have to use another 
                    data structure to store the real indices of the elements of the elements before sorting it*/
                        /*int arr[]={2,6,5,8,11};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int target,count=0,left=0,right=size-1;
                        cout<<"Enter target value: ";
                        cin>>target;
                        sort(arr,arr+size); // time complexity = O(nlogn)
                        while(left<right){ // time complexity = O(n)
                            if(arr[left]+arr[right]==target){
                                cout<<"Yes it is possible";
                                count++;
                                break;
                            }
                            else if(arr[left]+arr[right]<target) left++;
                            else right--;
                        }
                        if(count==0) cout<<"No it is not possible";*/
            // 2. sort array of 0,1,2 eg,[0,1,2,0,1,2,1,2,0,0,0,1]
                // brute force sol (time complexity = O(nlogn), space complexity = O(n))
                    /*vector<int>arr={0,1,2,0,1,2,1,2,0,0,0,1};
                    int size=arr.size();
                    div(arr,0,size-1); // time complexity = O(nlogn), space complexity = O(n)
                    for(auto i : arr) cout<<i<<" ";*/
                // better sol (time complexity = O(2n), space complexity = O(1))
                    /*int arr[]={0,1,2,0,1,2,1,2,0,0,0,1};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int count0=0,count1=0,count2=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(arr[i]==0)count0++;
                        else if(arr[i]==1)count1++;
                        else count2++;
                    }
                    for(int i=0;i<count0;i++)arr[i]=0; // time complexity = O(n/3)
                    for(int i=count0;i<count0+count1;i++)arr[i]=1; // time complexity = O(n/3)
                    for(int i=count0+count1;i<size;i++)arr[i]=2; // time complexity = O(n/3)
                    for(int i=0;i<size;i++)cout<<arr[i]<<" ";*/
                // optimal sol (time complexity = O(n), space complexity = O(1))
                    /*// Dutch National Flag Algorithm
                        // it uses three pointers approach low,mid,and high
                        // everything from 0 to low-1 = 0 that is extreme left
                        // everything from low to mid-1 = 1 
                        // everything from high+1 to sizeofarray-1 = 2 that is extreme right for example given below
                        // 0-------low-1 low-------mid-1 mid---------high high+1-------sizeofarray-1 -> index
                        // 0000000000000 111111111111111 randomunsortedno 22222222222222222222222222 -> values*/
                        /*int arr[]={0,1,2,0,1,2,1,2,0,0,0,1}; // array comes under mid to high category
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int low=0,mid=0,high=size-1;
                        while(mid<=high){ // time complexity = O(n)
                            if(arr[mid]==0){
                                swap(arr[mid],arr[low]);
                                low++;
                                mid++;
                            }
                            else if(arr[mid]==1) mid++;
                            else{
                                swap(arr[mid],arr[high]);
                                high--;
                            }
                        }
                        for(int i=0;i<size;i++)cout<<arr[i]<<" ";*/
            // 3. majority element that occurs more than n/2 times in the array
                // brute force sol (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={2,2,3,3,1,2,2};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int count=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        count=0;
                        for(int j=0;j<size;j++){ // time complexity = O(n)
                            if(arr[j]==arr[i]) count++;
                        }
                        if(count>size/2){
                            cout<<arr[i];
                            break;
                        }
                    }
                    if(count<=size/2)cout<<"No majority element";*/
                // better sol (time complexity = O(nlogn)+O(n), space complexity = O(n))
                    /*int arr[]={2,2,3,3,1,2,2};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int res=0;
                    map<int,int>hash; // space complexity = O(n)
                    for(int i=0;i<size;i++)hash[arr[i]]++; // time complexity = O(nlogn) n for outer loop and logn for map
                    for(auto i : hash)if(i.second>size/2)res=i.first; // time complexity = O(n)
                    if(res==0)cout<<"No majority element";
                    else cout<<res;*/
                // optimal sol (time complexity = O(2n), space complexity = O(1))
                    /*apply Moore's Voting Algorithm
                        eg-7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5
                        1.take an element(7) and count i.e,7=1 -> 7=2 -> 5=1(-1) -> 7=2 -> 5=1(-1) -> 1=0(-1) => count=0 go step2
                        2.take another element(5) and count i.e,5=1 -> 7=0(-1) => count=0 go to step 3
                        3.take another element(5) and count i.e,5=1 -> 5=2 -> 7=1(-1) -> 7=0(-1) => count=0 go to step 4
                        4.take another element(5) and count i.e,5=1 -> 5=2 -> 5=3 -> 5=4 => count=4 and array ends
                        so element that lasts will be the most occuring array
                        verify if the element that lasts is most occuring or not
                        iterate the array again and count the element that we got*/
                            /*int arr[]={7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int count=0,el;
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if(count==0){
                                    count=1;
                                    el=arr[i];
                                }
                                else if(arr[i]==el)count++;
                                else count--;
                            }
                            int cnt=0;
                            for(int i=0;i<size;i++){ // time complexity = O(n) this is not use if problem says there is definitely a mojority element .. it is used to check whether have or not have condition
                                if(arr[i]==el)cnt++;
                            }
                            if(cnt>size/2)cout<<el;
                            else cout<<"No majority element";*/
            // 4. max subarray sum using kadane's algorithm eg, -2,-3,4,-1,-2,1,5,-3 => max sum = 7
                // brute force sol (time complexity = O(n^3), space complexity = O(1))
                    /*int arr[]={-2,-3,4,-1,-2,1,5,-3};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int maxx=INT_MIN;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            int sum=0;
                            for(int k=i;k<j;k++) sum += arr[k]; // time complexity = O(n)
                            maxx=max(sum,maxx);
                        }
                    }
                    cout<<maxx;*/
                // better sol (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={-2,-3,4,-1,-2,1,5,-3};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int maxx=INT_MIN;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        int sum=0;
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            sum += arr[j]; 
                            maxx=max(sum,maxx);
                        }
                    }
                    cout<<maxx;*/
                // optimal sol (time complexity = O(n), space complexity = O(1))
                    /*Kadane's Algorithm 
                        eg, -2,-3,4,-1,-2,1,5,-3
                        updating sum if it is greater than 0 if not just reset it 0
                        maxsum=int_min,sum=0
                        -2
                        sum=-2, maxsum=-2 => max(maxsum,sum)
                        -3
                        sum=0, maxsum=-2
                        4
                        sum=4, maxsum=4
                        -1
                        sum=3, maxsum=4
                        -2
                        sum=1, maxsum=4
                        1
                        sum=2, maxsum=4
                        5
                        sum=7, maxsum=7
                        -3
                        sum=4, maxsum=7*/
                        /*int arr[]={-2,-3,4,-1,-2,1,5,-3};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int maxx=INT_MIN;
                        int sum=0;
                        int substart=-1, subend=-1, start=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(sum==0) start=i; // for printing subarray
                            sum += arr[i];
                            if(sum>maxx){
                                maxx=sum;
                                substart=start; // for printing subarray
                                subend=i; // for printing subarray
                            }
                            if(sum<0) sum=0;
                        }
                        if(maxx<0) maxx=0;
                        cout<<maxx<<endl;
                        for(int i=substart;i<=subend;i++) cout<<arr[i]<<" "; // for printing the subarray*/
            // 5. stock buy and sell 
                // i. best time to buy and sell stock only one time (time complexity = O(n), space complexity = O(1))
                    /*eg, [7,1,5,3,6,4] = > price of stocks, and indices => days, now select a day when you buy the stock and when you sell the stock in order to maximize the profit
                    for eg, if i buy at second day day it costs me 1rs and sell it on fifth day it makes me profit of 5rs
                    buy has to be done before selling i.e, we cant buy it at second day with 1rs and sell it at first of 7rs*/
                        /*int price[]={7,1,5,3,6,4};
                        int size=sizeof(price)/sizeof(price[0]);
                        int minpricetobuy=price[0], maxprofit=0;
                        for(int i=1;i<size;i++){ // time complexity = O(n)
                            int profit_generated_on_selling_on_ith_day=price[i]-minpricetobuy;
                            maxprofit=max(maxprofit,profit_generated_on_selling_on_ith_day);
                            minpricetobuy=min(minpricetobuy,price[i]);
                        } 
                        cout<<"Max profit that can be generated: "<<maxprofit;*/
                // ii. best time to buy and sell stock multiple times (time complexity = O(2^n), space complexity = O(n) auxiliary stack space)
                    /*eg, [7,1,5,3,6,4] = > price of stocks, and indices => days, now select days when you buy the stock and when you sell the stock in order to maximize the profit 
                    in above stock prices if we buy at 2nd day with 1rs and sell it on 3rd day at 5rs it profits me 4rs
                    then if we buy on 4th day at 3rs and sell it on 4th day at 6rs it profits me 3rs
                    together it makes me 4rs + 3rs = 7rs profit
                    buy and sell has to be contiguos in order to buy another stock we can't buy, buy and then sell, sell*/
                        /*int price[]={7,1,5,3,6,4};
                        int size=sizeof(price)/sizeof(price[0]);
                        int res=maxprofit(price,size,0,1);
                        cout<<"Max profit that can be generated: "<<res;*/
            // 6(i). rearrange array by alternating pos and neg items eg, 3,1,-2,-5,2,-4 (n/2=>+ve elements, n/2=>-ve elements) => +ve -ve +ve -ve order i.e, ans=3,-2,1,-5,2,-4
                // brute force sol(time complexity = O(n+(n/2)), space complexity = O(n))
                    /*int arr[]={3,1,-2,-5,2,-4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    list <int> pos,neg; // space complexity = O(n)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(arr[i]>0) pos.push_back(arr[i]);
                        else neg.emplace_back(arr[i]);
                    }
                    auto p=pos.begin(),n=neg.begin();
                    for(int i=0;i<size/2;i++){ // time complexity = O(n/2)
                        arr[2*i]=*p;
                        ++p;
                        arr[2*i+1]=*n;
                        ++n;
                    }
                    for(auto i : arr) cout<<i<<" ";*/
                // optimal sol (time complexity = O(n), space complexity = O(n))
                    /*int arr[]={3,1,-2,-5,2,-4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int ans[size]; // space complexity = O(n)
                    int pos=0, neg=1;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(arr[i]>0){
                            ans[pos]=arr[i];
                            pos+=2;
                        }
                        else{
                            ans[neg]=arr[i];
                            neg+=2;
                        }
                    }
                    for(auto i : ans) cout<<i<<" ";*/
            // 6(ii). rearrange array by alternating pos and neg items eg, -1,2,3,4,-3,1 => +ve -ve +ve -ve order i.e, ans=2,-1,3,-3,4,1
                // optimal sol (time complexity = O(2n), space complexity = O(n))
                    /*int arr[]={-1,2,3,4,-3,1};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    vector <int> pos, neg; // time complexity = O(n)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(arr[i]>0) pos.push_back(arr[i]);
                        else neg.push_back(arr[i]);
                    }
                    if(pos.size()>neg.size()){ // time complexity = O(min(pos,neg))
                        for(int i=0;i<neg.size();i++){ // for filling first possible alternate combinations
                            arr[2*i]=pos[i];
                            arr[2*i+1]=neg[i];
                        }
                        int ind=2*neg.size();
                        for(int i=neg.size();i<pos.size();i++){ // time complexity = O(remaining)
                            arr[ind]=pos[i];
                            ind++;
                        }
                    }
                    else{
                        for(int i=0;i<pos.size();i++){ // for filling first possible alternate combinations
                            arr[2*i]=pos[i];
                            arr[2*i+1]=neg[i];
                        }
                        int ind=2*pos.size();
                        for(int i=pos.size();i<neg.size();i++){
                            arr[ind]=neg[i];
                            ind++;
                        }
                    }
                    // in this O(min(pos,neg)) min value => no pos(0) or no neg(0) => 0 implies O(rem) = n
                    //                         max value => half pos(n/2) or half neg(n/2) => n implies O(rem) = 0
                    // so O(min(pos,neg)+remaining) = O(n) in worst case => total time complexity = O(n+n)=O(2n)
                    for(auto i : arr) cout<<i<<" ";*/
            // 7. next permutation eg, [3,1,2]
                /*all permutations (i.e, sorted order as per dictionary = n! = 3! = 3*2*1 = 6);
                123,132,213,231,312,321 so next permutation of 3,1,2 is 3,2,1 then of 3,2,1 is 1,2,3*/
                    // brute force sol using recursion (time complexity = O(n!*n))
                        /*int arr[]={3,1,2};*/
                    // optimal sol (time complexity = O(3n) in worst case, space complexity = O(1))
                        /*vector <int> arr={3,1,2};
                        int breakpoint=-1;
                        // next_permutation(arr.begin(),arr.end()); for(auto i : arr) cout<<i<<" "; // this STL is explained below
                        int size=arr.size();
                        for(int i=size-2;i>=0;i--){ // find break point, time complexity = O(n)
                            if(arr[i]<arr[i+1]){
                                breakpoint=i;
                                break;
                            }
                        }
                        if(breakpoint==-1) reverse(arr.begin(),arr.end());
                        else{
                            for(int i=size-1;i>breakpoint;i--){ // time complexity = O(n)
                                if(arr[i]>arr[breakpoint]){
                                    swap(arr[i],arr[breakpoint]);
                                    break;
                                }
                            }
                            reverse(arr.begin()+breakpoint+1,arr.end()); // time complexity = O(n)
                        }
                        for(auto i : arr) cout<<i<<" ";*/
            // 8. leaders in the array (leader = everything of which is smaller than it eg; 10,22,12,3,6 => 22,12, and 6 are leaders as there right side all elements are smaller than them
                // brute force sol (time complexity = O(n^2), space complexity = O(n) to store the answer not to solve)
                    /*int arr[]={10,22,12,3,0,6};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    vector <int> leaders; // time complexity = O(n)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        bool lead=true;
                        for(int j=i+1;j<size;j++){ // time complexity = O(n)
                            if(arr[j]>arr[i]){
                                lead=false;
                                break;
                            }
                        }
                        if(lead==true) leaders.push_back(arr[i]);
                    }
                    for(auto i : leaders) cout<<i<<" ";*/
                // optimal sol (time complexity = O(n), space complexity = O(n))
                    /*int arr[]={10,22,12,3,0,6,0,0};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int maxx=INT_MIN;
                    vector <int> leaders; // space complexity = O(n)
                    for(int i=size-1;i>=0;i--){ // time complexity = O(n)
                        if(arr[i]>maxx){
                            leaders.push_back(arr[i]);
                            maxx=arr[i];
                        }
                    }
                    for(auto i : leaders) cout<<i<<" ";*/
            // 9. longest consecutive sequence of the array
                // eg; [102,4,100,1,101,1,3,2,1,1] => 1,2,3,4 = length is 4  or 100,101,102 = length is 3 so the ans is 4(length)
                    // brute force sol (time complexity = O(n^2), space complexity = O(1))
                        /*int arr[]={102,4,100,1,101,1,3,2,1,1};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int longestconseqlen=1, count=1;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            int x=arr[i];
                            for(int j=i+1;j<size;j++){ // time complexity = O(n)
                                if(arr[j]==x+1) count++;
                            }
                            longestconseqlen=max(longestconseqlen,count);
                        }
                        cout<<"Longest consecutive sequence that can be possible is of length: "<<longestconseqlen;*/
                    // better sol (time complexity = O(nlogn + n),space complexity = O(1))
                        /*vector <int> arr={100,102,100,101,101,4,3,2,3,2,1,1,1,2};
                        int size=arr.size();
                        div(arr,0,size-1); // time complexity = O(nlog)
                        int lastsmall=INT_MIN, count=0, longestconseqlen=1;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(lastsmall==arr[i]-1){
                                count+=1;
                                lastsmall=arr[i];
                            }
                            else if(arr[i] != lastsmall){
                                count=1;
                                lastsmall=arr[i];
                            }
                            longestconseqlen=max(longestconseqlen,count);
                        }
                        cout<<"Longest consecutive sequence that can be possible is of length: "<<longestconseqlen;*/
                    // optimal sol (time complexity = O(3n), space complexity = O(n))
                        /* this sol is only optimal in some constraints as assuming that unordered set is taking O(1) for all the operations
                        otherwise if it takes O(n) then it goes O(logn), in that case brute force is better one sol*/
                            /*vector <int> arr={100,102,100,101,101,4,3,2,3,2,1,1,1,2};
                            int size=arr.size();
                            unordered_set <int> ans; // space complexity = O(n)
                            for(auto i : arr) ans.insert(arr[i]); // time complexity = O(n)
                            int longestconseqlen=1,count=0;
                            // line 2299 and line 2303 != O(n^2) but, is equal to O(2n) in worst case as while loop is not for every element
                            for(auto i : ans){ // time complexity = O(n)
                                if(ans.find(i+1)==ans.end()){ // find start element
                                    int start=i;
                                    count++;
                                    while(ans.find(start+1) != ans.end()){ // time complexity = O(n)
                                        count += 1;
                                        start += 1;
                                    }
                                    longestconseqlen=max(longestconseqlen,count);
                                }
                            }
                            cout<<"Longest consecutive sequence that can be possible is of length: "<<longestconseqlen;*/
            // 10. set matrix zeros
                /*given a nxn binary matrix (i.e, only having 0 or 1)
                wherever 0 is found in the matrix just fill that row and column with 0
                don't do this thing with the 0 you fill only do with the 0 originally present in the initial array
                eg; | 1 | 1 | 1 | 1 |                        | 1 | 0 | 0 | 1 |   
                    | 1 | 0 | 0 | 1 |    => answer will be   | 0 | 0 | 0 | 0 |
                    | 1 | 1 | 0 | 1 |                        | 0 | 0 | 0 | 0 |
                    | 1 | 1 | 1 | 1 |                        | 1 | 0 | 0 | 1 |*/
                    // brute force sol (time complexity = O(n*m)*(n+m) + O(n*m) is nearly in ^3, space complexity = O(1))
                        /*int arr[][4]={{1,1,1,1},
                                    {1,0,0,1},
                                    {1,1,0,1},
                                    {1,1,1,1}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        for(int i=0;i<rows;i++){ // time complexity = O(n)
                            for(int j=0;j<cols;j++){ // time complexity = O(m)
                                if(arr[i][j]==0){
                                    // these two below loops take O(m+n)
                                    for(int k=0;k<rows;k++){ // time complexity = O(n)
                                        if(arr[i][k] != 0) arr[i][k]=-1;
                                    }
                                    for(int k=0;k<cols;k++){ // time complexity = O(m)
                                        if(arr[k][j] != 0) arr[k][j]=-1;
                                    }
                                }
                            }
                        }
                        for(int i=0;i<rows;i++){ // time complexity = O(n)
                            for(int j=0;j<cols;j++){ // time complexity = O(m)
                                if(arr[i][j]==-1) arr[i][j]=0;
                            }
                        }
                        for(int i=0;i<rows;i++){
                            for(int j=0;j<cols;j++) cout<<arr[i][j]<<" ";
                            cout<<endl;
                        }*/
                    // better sol (time complexity = O(n*m + n*m) = O(2n*m), space complexity = O(n+m))
                        /*int arr[][4]={{1,1,1,1},
                                    {1,0,1,1},
                                    {1,1,0,1},
                                    {1,0,0,1}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int rowtrack[rows]={0}; // space complexity = O(n)
                        int coltrack[cols]={0}; // space complexity = O(m)
                        for(int i=0;i<rows;i++){ // time complexity = O(n)
                            for(int j=0;j<cols;j++){ // time complexity = O(m)
                                if(arr[i][j]==0){
                                    rowtrack[i]=1;
                                    coltrack[j]=1;
                                }
                            }
                        }
                        for(int i=0;i<rows;i++){ // time complexity = O(n)
                            for(int j=0;j<cols;j++){ // time complexity = O(m)
                                if(rowtrack[i]==1 || coltrack[j]==1) arr[i][j]=0;
                            }
                        }
                        for(int i=0;i<rows;i++){
                            for(int j=0;j<cols;j++) cout<<arr[i][j]<<" ";
                            cout<<endl;
                        }*/
                    // optimal sol (time complexity = O(n*m + n*m) = O(2n*m), space complexity = O(1))
                        /*int arr[][4]={{1,1,1,1},
                                    {1,0,1,1},
                                    {1,1,0,1},
                                    {0,1,1,1}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        // int rowtrack[rows]={0}; => arr[][0] 0th col keep track the record of row mark
                        // int coltrack[cols]={0}; => arr[0][] 0th row keep track the record of col mark
                        int col0=1;
                        for(int i=0;i<rows;i++){ // time complexity = O(n)
                            for(int j=0;j<cols;j++){ // time complexity = O(m)
                                if(arr[i][j]==0){
                                    arr[i][0]=0; // mark i-th row
                                    if(j!=0) arr[0][j]=0; // mark j-th row but dont mark arr[0][0] element as it can mislead the output
                                    else col0=0; // mark 0th row if it has 0
                                }
                            }
                        }
                        // all loops from line 2395 to 2408 overall time iteration is n*m => time complexity = O(n*m)
                        for(int i=1;i<rows;i++){ // time complexity = O(n)
                            for(int j=1;j<cols;j++){ // time complexity = O(m)
                                if(arr[i][j] != 0){
                                    if(arr[i][0]==0 || arr[0][j]==0) arr[i][j]=0;
                                }
                            }
                        }
                        // now first mark the row0 then column0
                        // marking row 0
                        for(int i=1;i<cols;i++){ // time complexity = O(m)
                            if(arr[0][0]==0) arr[0][i]=0;
                        }
                        // marking column 0
                        for(int j=1;j<rows;j++){ // time complexity = O(n)
                            if(col0==0) arr[j][0]=0;
                        }
                        for(int i=0;i<rows;i++){
                            for(int j=0;j<cols;j++) cout<<arr[i][j]<<" ";
                            cout<<endl;
                        }*/
            // 11. rotate image / rotate matrix by 90 degrees
                /*an nxn matrix (i.e, square) is given and we need to rotate the matrix in clockwise direction by 90 degrees
                eg; | 1  | 2  | 3  | 4  |                        | 13 | 9  | 5 | 1 |   
                    | 5  | 6  | 7  | 8  |    => answer will be   | 14 | 10 | 6 | 2 |
                    | 9  | 10 | 11 | 12 |                        | 15 | 11 | 7 | 3 |
                    | 13 | 14 | 15 | 16 |                        | 16 | 12 | 8 | 4 |*/
                    // brute force sol (time complexity = O(n^2), space complexity = O(n^2))
                        /*int arr[][4]={{1,2,3,4},
                                    {5,6,7,8},
                                    {9,10,11,12},
                                    {13,14,15,16}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int ans[rows][cols]; // space complexity = O(n^2)
                        for(int i=0;i<rows;i++){ // time complexity = O(n)
                            for(int j=0;j<cols;j++) ans[j][rows-1-i]=arr[i][j]; // time complexity = O(n)
                        }
                        for(int i=0;i<rows;i++){
                            for(int j=0;j<cols;j++) cout<<ans[i][j]<<" ";
                            cout<<endl;
                        }*/
                    // optimal sol (time complexity = O(n^2)+O(n^2), space complexity = O(1))
                        /*int arr[][4]={{1,2,3,4},
                                    {5,6,7,8},
                                    {9,10,11,12},
                                    {13,14,15,16}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        // transpose the array
                        for(int i=0;i<rows;i++){ // time complexity = O(n)
                            for(int j=i+1;j<cols;j++) swap(arr[i][j],arr[j][i]); // time complexity = O(n)
                        }
                        // reverse every column
                        for(int i=0;i<rows;i++) reverse(arr[i],arr[i]+cols); // time complexity = O(n*n/2)=>n rows and n/2 for reverse using 2 pointers
                        for(int i=0;i<rows;i++){
                            for(int j=0;j<cols;j++) cout<<arr[i][j]<<" ";
                            cout<<endl;
                        }*/
            // 12. print matrix in a spiral manner / spiral traversal of matrix
                /*eg; | 1  | 2  | 3  | 4 |                        | 1  | 2  | 3  | 4  |   
                    | 12 | 13 | 14 | 5 |    => answer will be   | 5  | 6  | 7  | 8  |
                    | 11 | 16 | 15 | 6 |                        | 9  | 10 | 11 | 12 |
                    | 10 | 9  | 8  | 7 |                        | 13 | 14 | 15 | 16 |
                this problem has only one sol and that is optimal one (time complexity = O(nxm), space complexity = O(nxm))*/
                    /*int arr[][4]={{1,2,3,4},
                                {12,13,14,5},
                                {11,16,15,6},
                                {10,9,8,7}};
                    int rows=sizeof(arr)/sizeof(arr[0]);
                    int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                    int top=0, left=0, bottom=rows-1, right=cols-1;
                    vector <int> ans; // space complexity = O(n^2)
                    while(bottom>=top && right>=left){ // time complexity = O(n^2)
                        // right traverse
                        for(int i=left;i<=right;i++) ans.push_back(arr[top][i]);
                        // bottom traverse
                        top++;
                        for(int i=top;i<=bottom;i++) ans.push_back(arr[i][right]);
                        // left traverse
                        right--;
                        if(top<=bottom){
                            for(int i=right;i>=left;i--) ans.push_back(arr[bottom][i]);
                            bottom--;
                        }
                        // top traverse
                        if(left<=right){
                            for(int i=bottom;i>=top;i--) ans.push_back(arr[i][left]);
                            left++;
                        }
                    }
                    for(auto i : ans) cout<<i<<" ";*/
            // 13. find number of subarrays with given sum
                // brute force sol (time complexity = O(n^3), space complexity = O(1))
                    /*int arr[]={1,2,3,-3,1,1,1,4,2,-3};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int sum, count=0;
                    cout<<"Enter sum: ";
                    cin>>sum;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            int s=0;
                            for(int k=i;k<=j;k++) s+=arr[k]; // time complexity = O(n)
                            if(s==sum) count++;
                        }
                    }
                    cout<<"Total subarrays: "<<count;*/
                // better sol(time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={1,2,3,-3,1,1,1,4,2,-3};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int sum, count=0;
                    cout<<"Enter sum: ";
                    cin>>sum;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        int s=0;
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            s += arr[j];
                            if(s==sum) count++;
                        }
                    }
                    cout<<"Total subarrays: "<<count;*/
                // optimal sol (time complexity = O(nlogn), space complexity = O(n))
                    /*int arr[]={1,2,3,-3,1,1,1,4,2,-3};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int sum;
                    cout<<"Enter sum: ";
                    cin>>sum;
                    map <int,int> prefixsum; // space complexity = O(n)
                    prefixsum[0] = 1;
                    int prefix_sum=0, count=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        prefix_sum += arr[i];
                        int remainingsum = sum-prefix_sum;
                        count += prefixsum[remainingsum]; // time complexity = O(logn)
                        prefixsum[prefix_sum] += 1;            
                    }
                    cout<<"Total subarrays: "<<count;*/
        // hard questions
            // 1. pascal's triangle
                /*                       1
                                    1       1
                                1       2       1
                            1       3       3       1
                        1       4       6       4       1
                    1       5       10      10      5       1 
                the first and last element will be one and the middle element of next row is the sum of above side two elements*/
                    // (i). find element at given place in pascal triangle
                        // brute force sol (time complexity = O(col-1), space complexity = O(1))
                            /*(row-1)C(col-1) = (row-1)! / (col-1)! * (row-col)! => time complexity = O(row-1)+O(col-1)+O(row-col)
                            eg, row=5, col=3 => ans=6 => (5-1)! / (3-1)!*(5-3)! = 4! / 2!*2! = 4*3*2*1 / 2*1*2*1 = 24/4 = 6
                            another shortcut; 4! / 2!*2! = 4*3*(2*1) / 2*1*(2*1) = 4*3 / 2*1
                            => if denominator is of 2 places then numerator must also go for 2 places*/
                                /*int row, col, res=1;
                                cout<<"Enter row: ";
                                cin>>row;
                                    cout<<"Enter column: ";
                                    cin>>col;
                                    int r=row, c=col;
                                    int element = pascaltriangleelement(r-1,c-1);
                                    cout<<element;
                                            // or
                                    // row-=1; col-=1;
                                    // for(int i=0;i<col;i++){ // time complexity = O(col-1)
                                    //     res=res*(row-i);
                                    //     res=res/(i+1);
                                    // }
                                    // cout<<res;*/
                    // (ii). print the given row of a pascal triangle
                        // brute force sol (time complexity = O(row*col) approx, and O(row-1) for second one)
                            /*// int row;
                            // cout<<"Enter row: ";
                            // cin>>row;
                            // for(int col=1;col<=row;col++){ // time complexity = O(row)
                            //     int res=pascaltriangleelement(row-1,col-1); // time complexity = O(row-1)  or col-1
                            //     cout<<res<<" ";
                            // }
                                    // or
                            int row, res=1;
                            cout<<"Enter row: ";
                            cin>>row;
                            row -= 1;
                            for(int col=0;col<row;col++){ // time complexity = O(row-1)
                                cout<<res<<" ";
                                res=res*(row-col);
                                res=res/(col+1);
                            }
                            cout<<1;*/
                        // optimal sol (time complexity = O(row), space complexity = O(1))
                            /*int row;
                            cout<<"Enter row: ";
                            cin>>row;
                            int res=1;
                            cout<<res<<" ";
                            for(int col=1;col<row;col++){ // time complexity = O(row)
                                res=(res*(row-col))/col;
                                cout<<res<<" ";
                            }*/
                    // (iii). print entire pascal triangle with given row
                        // brute force sol (time complexity = O(row^3) approx, space complexity = O(row*3) only to return answer not to solve)
                            /*int row;
                            cout<<"Enter row: ";
                            cin>>row;
                            vector <vector<int>> result; // space complexity = O(row*column)
                            for(int i=1;i<=row;i++){ // for row, time complexity = O(row)
                                vector <int> temp; // space complexity = O(row)
                                for(int j=1;j<=i;j++){ // for column, time complexity = O(row) approx
                                    int res=pascaltriangleelement(i-1,j-1); // time complexity = O(row-1)
                                    temp.push_back(res);
                                }
                                result.push_back(temp);
                            }
                            for(auto i : result){
                                for(auto j : i) cout<<j<<" ";
                                cout<<endl;
                            }*/
                        // optimal sol (time complexity = O(row^2), space complexity = O(1) not to solve just to return answer we are using vectors)
                            /*int row;
                            cout<<"Enter row: ";
                            cin>>row;
                            vector <vector<int>> ans;
                            for(int i=1;i<=row;i++){ // for row, time complexity = O(row)
                                vector <int> rows;
                                long long res=1;
                                rows.push_back(1);
                                for(int col=1;col<i;col++){ // for columns, time complexity = O(row)
                                    res=(res*(i-col))/col;
                                    rows.push_back(res);
                                }
                                ans.push_back(rows);
                            }
                            for(auto i : ans){
                                for(auto j : i) cout<<j<<" ";
                                cout<<endl;
                            }*/
            // 2. majority element occuring >n/3 times in the array
                // brute force sol (time complexity = O(n^2), space complexity = O(2) which is taken as O(1) that is constant)
                    /*there must be at max 2 elements that can appear more than n/3 times
                    for eg; if n=8 => n/3=2
                    => to have >n/3 occurence an element must appear atleast 3 times
                    if there are 2 elements that appear 3 times => n=6
                    but if we assume there are 3 elements that appear 3 times => n=9 which is not equal to 8
                    so there must be only 2 elements at max can be present in the array with >n/3 occurence*/
                        /*int arr[]={1,1,1,3,3,2,2,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        vector <int> ans; // space complexity = O(2)
                        // int occurence=size/3;
                        // int count=0;
                        // for(int i=0;i<size;i++){ // time complexity = O(n)
                        //     for(int j=0;j<size;j++){ // time complexity = O(n)
                        //         if(arr[i]==arr[j]) count++;
                        //     }
                        //     if(count > occurence || ans.size()==2){
                        //         if(find(ans.begin(),ans.end(),arr[i]) == ans.end()) ans.push_back(arr[i]);
                        //     }
                        //     count=0;
                        // }
                        // for(auto i : ans) cout<<i<<" ";
                                    // or
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(ans.size()==0 || ans[0]!=arr[i]){
                                int count=0;
                                for(int j=0;j<size;j++){ // time complexity = O(n)
                                    if(arr[j]==arr[i]) count++;
                                }
                                if(count>size/3) ans.push_back(arr[i]);
                            }
                            if(ans.size()==2) break;
                        }
                        for(auto i : ans) cout<<i<<" ";*/
                // better sol (time complexity = O(nlogn + n), space complexity = O(n+2) => O(n))
                    /*int arr[]={1,1,1,1,3,2,2,2};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    map <int,int> hash; // space complexity = O(n)
                    // for(int i=0;i<size;i++){ // time complexity = O(n)
                    //     if(hash.find(arr[i]) != hash.end()) hash[arr[i]]++; // time complexity = O(logn) => O(nlogn)
                    //     else hash[arr[i]]=1;
                    // }
                    // vector <int> ans; // space complexity = O(2)
                    // for(auto i : hash){ // time complexity = O(n)
                    //     if(ans.size()==2) break;
                    //     if(i.second > size/3) ans.push_back(i.first);
                    // }
                    // for(auto i :  ans) cout<<i<<" ";
                                    // or
                    int min_occurence = (size/3)+1;
                    vector <int> ans; // space complexity = O(2) => O(1)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        hash[arr[i]]++; // time complexity = O(logn) => O(nlogn)
                        if(hash[arr[i]] == min_occurence){
                            ans.push_back(arr[i]);
                        }
                        if(ans.size()==2) break;
                    }
                    for(auto i : ans) cout<<i<<" ";*/
                // optimal sol using Boyer Moore's Algorithm (time complexity = O(2n), space complexity = O(1))
                    /*int arr[]={1,1,1,1,3,2,2,2};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int element1, element2;
                    int count1=0, count2=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(count1==0 && arr[i]!=element1){
                            element1=arr[i];
                            count1++;
                        }
                        else if(count2==0 && arr[i]!=element2){
                            element2=arr[i];
                            count2++;
                        }
                        else if(element1==arr[i]) count1++;
                        else if(element2==arr[i]) count2++;
                        else{
                            count1--;
                            count2--;
                        }
                    }
                    int cnt1=0, cnt2=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(arr[i]==element1) cnt1++;
                        if(arr[i]==element2) cnt2++;
                    }
                    if(cnt1>size/3 && cnt2>size/3) cout<<element1<<" "<<element2;*/
            // 3. three sum problem i.e., 3 elements of array whose sum is 0 and return only unique triplets
                /* -1,0,1,2,2,-1,-4 => [-1,2(first occurence),-1] and [-1,2(second occurence),-1] and [2,2,-4] and [2,-1,-1] and [2,-1,-1] and [-4,2,2]
                    answer should be only [-1,2,-1] and [2,2,-4] */
                    // brute force sol (time complexity = O(n^3 + 3 + nlogn) => O(n^3 + nlogn), space complexity = O(2 * no. of triplets))
                        /*int arr[]={-1,0,1,2,2,-1,-4};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        set <vector <int>> ans; // space complexity = O(no. of triplets)
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            for(int j=i+1;j<size;j++){ // time complexity = O(n)
                                for(int k=j+1;k<size;k++){ // time complexity = O(n)
                                    if(arr[i]+arr[j]+arr[k]==0){
                                        vector <int> triplet = {arr[i],arr[j],arr[k]}; // space complexity = O(no. of triplets)
                                        sort(triplet.begin(),triplet.end()); // time complexity = O(3)
                                        ans.insert(triplet); // time complexity = O(logn) => O(nlogn)
                                    }
                                }
                            }
                        }
                        for(auto i : ans){
                            for(auto j : i) cout<<j<<" ";
                            cout<<endl;
                        }*/
                    // better sol (time complexity = O(n^2 + logm + 3) => O(n^2+logm), space complexity = O(no. of triplets + n + 3) => O(n + no. of triplets))
                        /*int arr[]={-1,0,1,2,2,-1,-4};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        set <vector <int>> ans; // space complexity = O(no. of triplets)
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            set <int> hash; // space complexity = O(n) approx
                            for(int j=i+1;j<size;j++){ // time complexity = O(n)
                                int thirdelement = -(arr[i]+arr[j]);
                                if(hash.find(thirdelement) != hash.end()){ // time complexity = O(logm) m=size of hash which is continously changing
                                    vector <int> triplet = {arr[i],arr[j],thirdelement}; // space complexity = O(3)
                                    sort(triplet.begin(),triplet.end()); // time complexity = O(3)
                                    ans.insert(triplet); 
                                }
                                hash.insert(arr[j]);
                            }
                        }
                        for(auto i : ans){
                            for(auto j : i) cout<<j<<" ";
                            cout<<endl;
                        }*/
                    // optimal sol (time complexity = O(nlogn + n*n) => O(nlogn + n^2), space complexity = O(no. of triplets + 3) => O(no. of triplets)) just to return the answer
                        /*int arr[]={-2,-2,-2,-1,-1,-1,0,0,0,2,2,2,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        sort(arr,arr+size); // time complexity = O(nlogn)
                        int j,k;
                        vector <vector <int>> ans; // space complexity = O(no. of triplets) => to return answer not to solve 
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(i>0 && arr[i] == arr[i-1]) continue;
                            j=i+1;
                            k=size-1;
                            while(j<k){ // time complexity = O(n)
                                int sum = arr[i]+arr[j]+arr[k];
                                if(sum < 0) j++;
                                else if(sum > 0) k--;
                                else{
                                    vector <int> temp = {arr[i],arr[j],arr[k]}; // space complexity = O(3) => to store the elements
                                    ans.push_back(temp);
                                    j++;
                                    k--;
                                    while(j<k && arr[j]==arr[j-1]) j++; // time complexity = negligible
                                    while(j<k && arr[k]==arr[k+1]) k--; // time complexity = negligible
                                }
                            }
                        }
                        for(auto i : ans){
                            for(auto j : i) cout<<j<<" ";
                            cout<<endl;
                        }*/
            // 4. four sum problem i.e., 4 indices of array whose elements give the target sum ans return only unique quadruple
                // brute force sol (time complexity = O(n^4 * logn * 4) => O(n^4), space complexity = O(no. of quadruples + 4) => O(no. of quadruples))
                    /*int arr[]={1,0,-1,0,-2,2};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int target;
                    cout<<"Enter target sum: ";
                    cin>>target;
                    set <vector <int>> ans; // space complexity = O(no. of quadruples)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i+1;j<size;j++){ // time complexity = O(n)
                            for(int k=j+1;k<size;k++){ // time complexity = O(n)
                                for(int l=k+1;l<size;l++){ // time complexity = O(n)
                                    long long sum = arr[i]+arr[j];
                                    sum+=arr[k];
                                    sum+=arr[l];
                                    if(sum==target){
                                        vector <int> temp = {arr[i],arr[j],arr[k],arr[l]}; // space complexity = O(4)
                                        sort(temp.begin(),temp.end()); // time complexity = O(4)
                                        ans.insert(temp); // time complexity = O(logn)
                                    }
                                }
                            }
                        }
                    }
                    for(auto i : ans){
                        for(auto j : i) cout<<j<<" ";
                        cout<<endl;
                    }*/
                // better sol (time complexity = O(n^3 * 4 * logn) => O(n^3 * logn), space complexity = O(no. of quadruples + n + 4) => O(no. of quadriples + n))
                    /*int arr[]={1,0,-1,0,-2,2};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int target;
                    cout<<"Enter target sum: ";
                    cin>>target;
                    set <vector <int>> ans; // space complexity = O(no. of quadruples)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i+1;j<size;j++){ // time complexity = O(n)
                            set <int> hash; // space complexity = O(m) => m is the size of hash i.e., elements b/w j and k pointers nearly n at average
                            for(int k=j+1;k<size;k++){ // time complexity = O(n)
                                long long sum = arr[i]+arr[j];
                                sum+=arr[k];
                                long long fourthelement = target-sum;
                                if(hash.find(fourthelement) != hash.end()){
                                    vector <int> temp = {arr[i],arr[j],arr[k],int(fourthelement)}; // space complexity = O(4)
                                    sort(temp.begin(),temp.end()); // time complexity = O(4)
                                    ans.insert(temp); 
                                }
                                hash.insert(arr[k]); // time complexity = O(logm) = O(logn)
                            }
                        }
                    }
                    for(auto i : ans){
                        for(auto j : i) cout<<j<<" ";
                        cout<<endl;
                    }*/
                // optimal sol (time complexity = O(nlogn+n*n*n) => O(nlogn+n^3), space complexity = O(no. of quadruples+4) => O(no. of quadruples))
                    /*int arr[]={1,1,1,2,2,2,3,3,3,4,4,4,5,5};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    sort(arr,arr+size); // time complexity = O(nlogn)
                    int target;
                    cout<<"Enter target sum: ";
                    cin>>target;
                    vector <vector <int>> ans; // space complexity = O(no. of quadruples)
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        if(i>0 && arr[i]==arr[i-1]) continue;
                        for(int j=i+1;j<size;j++){ // time complexity = O(n)
                            if(j>i+1 && arr[j]==arr[j-1]) continue;
                            int k=j+1;
                            int l=size-1;
                            while(k<l){ // time complexity = O(n) approx
                                long long sum = arr[i];
                                sum+=arr[j];
                                sum+=arr[k];
                                sum+=arr[l];
                                if(sum < target) k++;
                                else if(sum > target) l--;
                                else{
                                    vector <int> temp = {arr[i],arr[j],arr[k],arr[l]}; // space complexity = O(4)
                                    ans.push_back(temp);
                                    k++;
                                    l--;
                                    while(k<l && arr[k]==arr[k-1]) k++; // time complexity = negligible
                                    while(k<l && arr[l]==arr[l+1]) l--; // time complexity = negligible
                                }
                            }
                        }
                    }
                    for(auto i : ans){
                        for(auto j : i) cout<<j<<" ";
                        cout<<endl;
                    }*/
            // 5. largest subarray length having sum zero from an array containing both positive and negative integers
                // brute force sol (time complexity = O(n^3), space complexity = O(1))
                    /*int arr[]={1,-1,3,2,-2,-8,1,7,10,23};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int length=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            int sum=0;
                            for(int k=i;k<=j;k++) sum+=arr[k]; // time complexity = O(n)
                            if(sum==0) length=max(length,(j-i+1));
                        }
                    }
                    cout<<"Max subarray length: "<<length;*/
                // better sol (time complexity = O(), space complexity = O())
                    /*int arr[]={1,-1,3,2,-2,-8,1,7,10,23};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int length=0;
                    for(int i=0;i<size;i++){
                        int sum=0;
                        for(int j=i;j<size;j++){
                            sum+=arr[j];
                            if(sum==0) length=max(length,j-i+1);
                        }
                    }
                    cout<<"Max subarray length: "<<length;*/
                // optimal sol using Kadane's Algorithm of storing prefix sum and hash map (time complexity = O(nlogn), space complexity = O(n))
                    /*int arr[]={1,-1,3,2,-2,-8,1,7,10,23};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int length=0;
                    int maxlength=0;
                    map <int,int> hash; // space complexity = O(n)
                    int sum=0;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        sum+=arr[i];
                        if(sum==0) maxlength=i+1;
                        if(hash.find(sum) != hash.end()){ // time complexity = O(logn)
                            length=i-hash[sum];
                            maxlength=max(length,maxlength);
                        }
                        else hash[sum]=i;
                    }
                    cout<<"Max subarray length: "<<maxlength;*/
            // 6. no. of subarrays having xor k
                // brute force sol (time complexity = O(n^3), space complexity = O(1))
                    /*int arr[]={4,2,2,6,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int x;
                    cout<<"Enter xor value: ";
                    cin>>x;
                    int count=0;
                    for(int i=0;i<size;i++){ // time compplexity = O(n)
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            int Xor=0;
                            for(int k=i;k<=j;k++) Xor=Xor^arr[k]; // time complexity = O(n)
                            if(Xor==x) count++;
                        }
                    }
                    cout<<"No. of subarrays having xor k: "<<count;*/
                // better sol (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={4,2,2,6,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int x;
                    cout<<"Enter xor value: ";
                    cin>>x;
                    int count=0;
                    for(int i=0;i<size;i++){ // time compplexity = O(n)
                        int Xor=0;
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            Xor=Xor^arr[j];
                            if(Xor==x) count++;
                        }
                    }
                    cout<<"No. of subarrays having xor k: "<<count;*/
                // optimal sol (time complexity = O(), space complexity = O())
                    /*[4,2,2,6,4] => Xor=4^2^2^6 as i is at 6 i.e.,3rd index
                                => 2^2^6 i.e, from i=1 to i=3 xor=x (given xor) and 4 i.e, i=0 as remainxor
                                => remainxor ^ x = xor
                                => taking ^ x both sides => remainxor ^ x ^ x = xor ^ x
                                => remainxor = xor ^ x
                                => for someone has to x (given xor) 
                                => someone has to remainxor i.e, xor ^ x
                                => remainxor=(4^2^2^6)^6 = 4
                                => check in map if remainxor exists from the start of the array
                                => if yes then count++ as if remainxor exists then the x (given xor) must also exists*/
                        /*int arr[]={4,2,2,6,4};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int x;
                        cout<<"Enter xor value: ";
                        cin>>x;
                        int Xor=0, count=0;
                        map <int,int> prexor; // space complexity = O(n)
                        prexor[0]=1;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            Xor=Xor^arr[i];
                            int remainxor=Xor^x;
                            if(prexor.find(remainxor) != prexor.end()) count+=prexor[remainxor]; // time complexity = O(logn)
                                            // or
                            // count+=prexor[remainxor];
                            prexor[Xor]++;
                        }
                        cout<<"No. of subarrays having xor k: "<<count;*/
            // 7. merge overlapping subintervals of array
                /*[(1,3),(2,6),(8,9),(9,11),(8,10),(2,4),(15,18),(16,17)]
                => 1  2  3  4  5  6  8  9  10  11  15  16  17  18
                    -------
                    -------------
                                    ----
                                        ---------
                                    --------
                    -------
                                                    --------------
                                                        ------
                => [1  2  3  4  5  6]  ,  [8  9  10  11]  ,  [15  16  17  18]
                    -------                ----               --------------
                        -------                ---------           ------
                        -------------       --------
                => overlapping subarrays that can be possible (1,6), (8,11), and (15,18) => 3 subarrays*/
                    // brute force sol (time complexity = O(nlogn + 2n), space complexity = O(n))
                        /*vector <vector <int>> arr = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
                        sort(arr.begin(),arr.end()); // time complexity = O(nlogn)
                        int size=arr.size();
                        vector <vector <int>> ans; // space complexity = O(n)
                        // time complexity of given loops at line 3014 and 3018 is 2n as they both together just iterate every element two times in the vector
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            int start=arr[i][0];
                            int end=arr[i][1];
                            if(!ans.empty() && end<=ans.back()[1]) continue; // ans.back() access the previous interval store in the ans and [1] accees the second element of interval
                            for(int j=i+1;j<size;j++){ // time complexity = O(n)
                                if(arr[j][0] <= end) end=max(end,arr[j][1]);
                                else break;
                            }
                            ans.push_back({start,end});
                        }
                        for(auto i : ans) cout<<"("<<i[0]<<","<<i[1]<<") ";*/
                    // optimal sol (time complexity = O(nlogn + n), space complexity = O(n))
                        /*vector <vector <int>> arr = {{1,3},{2,6},{8,9},{9,11},{8,10},{2,4},{15,18},{16,17}};
                        int size=arr.size();
                        sort(arr.begin(),arr.end()); // time complexity = O(nlogn)
                        vector <vector <int>> ans; // space complexity = O(n)
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(ans.empty() || arr[i][0]>=ans.back()[1]) ans.push_back(arr[i]);
                            else ans.back()[1]=max(ans.back()[1],arr[i][1]);
                        }
                        for(auto i :  ans) cout<<"("<<i[0]<<","<<i[1]<<") ";*/
            // 8. merge two sorted arrays without using any extra space
                // brute force sol uses extra space(time complexity = O(2(m+n)), space complexity = O(m+n))
                    /*int arr1[]={1,3,5,7};
                    int arr2[]={0,2,6,8,9};
                    int size1=sizeof(arr1)/sizeof(arr1[0]);
                    int size2=sizeof(arr2)/sizeof(arr2[0]);
                    int size3=size1+size2;
                    int arr3[size3]; // space complexity = O(m+n) the size of the given arrays
                    int ptr1=0;
                    int ptr2=0;
                    int i=0;
                    while(ptr1<size1 && ptr2<size2){ // time complexity = O(m+n)
                        if(arr1[ptr1]<=arr2[ptr2]) arr3[i++]=arr1[ptr1++];
                        else arr3[i++]=arr2[ptr2++];
                    }
                    while(ptr1<size1) arr3[i++]=arr1[ptr1++]; // time complexity = optional as it depends if the arr1 still has the remaining elements
                    while(ptr2<size2) arr3[i++]=arr2[ptr2++]; // time complexity = optional as it depends if the arr2 still has the remaining elements
                    for(int j=0;j<size3;j++){ // time complexity = O(m+n)
                        if(j<size1) arr1[j]=arr3[j];
                        else arr2[j-size1]=arr3[j];
                    }
                    for(int j=0;j<size1;j++) cout<<arr1[j]<<" ";
                    cout<<endl;
                    for(int j=0;j<size2;j++) cout<<arr2[j]<<" ";*/
                // better sol (time complexity = O(min(m+n) + nlogn + mlogm), space complexity = O(1))
                    /*int arr1[]={1,3,5,7};
                    int arr2[]={0,2,6,8,9};
                    int size1=sizeof(arr1)/sizeof(arr1[0]);
                    int size2=sizeof(arr2)/sizeof(arr2[0]);
                    int ptr1=size1-1;
                    int ptr2=0;
                    while(ptr1>=0 && ptr2<size2 && arr1[ptr1]>arr2[ptr2]){ // time complexity = O(min(m+n)) at worst
                        swap(arr1[ptr1],arr2[ptr2]);
                        ptr1--;
                        ptr2++;
                    }
                    sort(arr1,arr1+size1); // time complexity = O(nlogn)
                    sort(arr2,arr2+size2); // time complexity = O(mlogm)
                    for(int i=0;i<size1;i++) cout<<arr1[i]<<" ";
                    cout<<endl;
                    for(int i=0;i<size2;i++) cout<<arr2[i]<<" ";*/
                // optimal sol uses gap method that uses shell sort (time complexity = O(log base2 (m+n) * (m+n)), space complexity = O(1))
                    /*int arr1[]={1,3,5,7};
                    int arr2[]={0,2,6,8,9};
                    int size1=sizeof(arr1)/sizeof(arr1[0]);
                    int size2=sizeof(arr2)/sizeof(arr2[0]);
                    int size3=size1+size2;
                    int gap=ceil(double(size3)/2); // or size3/2 + size3%2 => 9/2 + 9%2 => 4+1 = 5
                    while(gap>0){ // time complexity = O(log base2 (m+n)) as it is becoming half after every iteration
                        int ptr1=0;
                        int ptr2=ptr1+gap;
                        while(ptr2<size3){ // time complexity = O(m+n) as it is covering nearly all the elements of both the arrays
                            if(ptr1<size1 && ptr2>=size1){ // ptr1 in arr1 and ptr2 in arr2
                                int ind2=ptr2-size1;
                                if(arr1[ptr1]>arr2[ind2]) swap(arr1[ptr1],arr2[ind2]);
                            }
                            else if(ptr1>=size1){ // ptr1 and ptr2 both in arr2
                                int ind1=ptr1-size1;
                                int ind2=ptr2-size1;
                                if(arr2[ind1]>arr2[ind2]) swap(arr2[ind1],arr2[ind2]);
                            }
                            else{ // ptr1 and ptr2 both in arr1
                                if(arr1[ptr1]>arr1[ptr2]) swap(arr1[ptr1],arr1[ptr2]);
                            }
                            ptr1++;
                            ptr2++;
                        }
                        if(gap==1) break;
                        gap=ceil(double(gap)/2);
                    }
                    for(int i=0;i<size1;i++) cout<<arr1[i]<<" ";
                    cout<<endl;
                    for(int i=0;i<size2;i++) cout<<arr2[i]<<" ";*/
            // 9. finding repeating and missing numbers
                /* [4,3,6,2,1,1] => n=6 that should be [1,2,3,4,5,6] or in any order
                    answer will be [repeating number, missing number] => [1,5]*/
                    // brute force sol (time complexity = O(n^2), space complexity = O(1))
                        /*int arr[]={4,3,6,2,1,1};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int repeating_number=0;
                        int missing_number=0;
                        for(int i=1;i<=size;i++){ // time complexity = O(n)
                            if(repeating_number!=0 && missing_number!=0) break;
                            int count=0;
                            for(int j=0;j<size;j++){ // time complexity = O(n)
                                if(arr[j]==i) count++;
                            }
                            if(count==2) repeating_number=i;
                            else if(count==0) missing_number=i;
                        }
                        cout<<"Repeating number: "<<repeating_number<<endl;
                        cout<<"Missing number: "<<missing_number;*/
                    // better sol (time complexity = O(2n), space complexity = O(n+1))
                        /*int arr[]={4,3,6,2,1,1};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int hash[size+1]={0}; // space complexity = O(size+1) to store the nth element i.e., n=6 to store 6 as index, hash size must be 7
                        int repeating_number=0;
                        int missing_number=0;
                        for(int i=0;i<size;i++) hash[arr[i]]++; // time complexity = O(n)
                        for(int i=1;i<=size;i++){ // time complexity = O(n)
                            if(repeating_number!=0 && missing_number!=0) break;
                            if(hash[i]==2) repeating_number=i;
                            else if(hash[i]==0) missing_number=i;
                        }
                        cout<<"Repeating number: "<<repeating_number<<endl;
                        cout<<"Missing number: "<<missing_number;*/
                    // optimal sol 1 uses basic maths (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={4,3,6,2,1,1};
                        long long size=sizeof(arr)/sizeof(arr[0]);
                        long long sumofarr=(size*(size+1))/2; // formula of first n natural numbers sum
                        long long sum1=0;
                        long long squaresumofarr=(size*(size+1)*((2*size)+1))/6; // formula of first n natural numbers square sum
                        long long sum2=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            sum1+=arr[i];
                            sum2+=(long long)arr[i] * (long long)arr[i];
                        }
                        long long eqn1=sum1-sumofarr; // eqn1=rep-miss
                        long long eqn2=sum2-squaresumofarr; // eqn2=rep^2-miss^2 => eqn2=(rep-miss)(rep+miss) => eqn2=eqn1(rep+miss) => rep+miss=eqn2/eqn1 => eqn2=eqn2/eqn1
                        eqn2=eqn2/eqn1;
                        long long repeating_number=(eqn1+eqn2)/2;  // eqn1=rep-miss, eqn2=rep+miss => adding both eqns => eqn1+eqn2=2rep => rep=(eqn1+eqn)/2
                        long long missing_number=repeating_number-eqn1; // eqn1=rep-miss => miss=rep-eqn1
                        cout<<"Repeating number: "<<(int)repeating_number<<endl;
                        cout<<"Missing number: "<<(int)missing_number;*/
                    // optimal sol 2 uses xor concepts (time complexity = O(3n), space complexity = O(1))
                        /*int arr[]={4,3,6,2,1,1};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int xr=0;
                        // (4^3^6^2^1^1) ^ (1^2^3^4^5^6) = 1^5 = 4 (the following loops will give)
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            xr=xr^arr[i];
                            xr=xr^(i+1);
                        }
                        // bin(4)=1 0 0 
                        //        2 1 0 = bit position => we need to find the first rightmost bit having 1 that is 2nd bit 
                        // 4 & 1<<0 => 4 & 1 => 100 & 001 => 000 false loop still continue with bitno as 1
                        // 4 & 1<<1 => 4 & 2 => 100 & 010 => 000 false loop still continue with bitno as 2
                        // 4 & 1<<2 => 4 & 4 => 100 & 100 => 100 true loop breaks with bitno as 2
                        int bitno=0;
                        while(1){
                            if((xr & (1<<bitno)) != 0) break;
                            bitno++;
                        }
                        // we have to classify all the elements with having 2nd bit as 0 or 1
                        // we have 4 3 6 2 1 1 and 1 2 3 4 5 6
                        // for 4; 4 & 1<<2 => 4 & 4 => 100 & 100 => 100 which is not equal to 0 => it is of oneclub
                        // for 3; 3 & 1<<2 => 3 & 4 => 010 & 100 => 000 = 0 => it is of zeroclub
                        // similarly with all the remaining elements, finally we have:
                        // zeroclub    oneclub
                        //     3           4
                        //     2           6
                        //     1           4
                        //     1           5
                        //     1           6
                        //     2
                        //     3
                        // now zeroclub = 3^2^1^1^1^2^3 = 1 => repeating number but still not know
                        //     oneclub = 4^6^4^5^6 = 5 => missing number but still not known
                        // now we know only 1 and 5 are the answers
                        int zeroclub=0;
                        int oneclub=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if((arr[i] & (1<<bitno)) != 0) oneclub=oneclub^arr[i];
                            else zeroclub=zeroclub^arr[i];
                            if(((i+1) & (1<<bitno)) != 0) oneclub=oneclub^(i+1);
                            else zeroclub=zeroclub^(i+1);
                        }
                        // we have 4 3 6 2 1 1
                        // if 4 == 1 no
                        // if 3 == 1 no
                        // if 6 == 1 no
                        // if 2 == 1 no
                        // if 1 == 1 yes => count=1
                        // if 1 == 1 yes => count=1
                        // if count=2 then it is repeating number or if count=0 then it is missing number
                        int count=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(arr[i]==zeroclub) count++;
                        }
                        if(count==2){
                            cout<<"Repeating number: "<<zeroclub<<endl;
                            cout<<"Missing number: "<<oneclub;
                        }
                        else{
                            cout<<"Repeating number: "<<oneclub<<endl;
                            cout<<"Missing number: "<<zeroclub;
                        }*/
            // 10. count inversions (the no. pairs such that previous element > precedent element)
                /*[5 3 2 4 1] 
                (5,3) (5,2) (5,4) (5,1) = possible = 4
                (3,2) (3,1) = possible = 2
                (2,1) = possible = 1
                (4,1) = possible = 1
                (3,4) (2,4) = not possible
                also (4,3) (4,2) = not possible as we have to move only in forward direction not in backward 
                so, the answer will be 4+2+1+1=8*/
                    // brute force sol (time complexity = O(n^2), space complexity = O(1))
                        /*int arr[]={5,3,2,4,1};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int count=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            for(int j=i+1;j<size;j++){ // time complexity = O(n)
                                if(arr[i]>arr[j]) count++;
                            }
                        }
                        cout<<"No. pairs: "<<count;*/
                    // better sol using merge sort (time complexity = O(nlogn), space complexity = O(n)) but the array is altered to a sorted array
                        /*vector <int> arr = {5,3,2,4,1};
                        int size=arr.size();
                        cout<<"No. of pairs: "<<Div(arr,0,size-1);*/
            // 11. count reverse pairs (the no. of pairs such that previous element > 2*precedent element)
                /*[40,25,19,12,9,6,2]
                (40,19) (40,12) (40,9) (40,6) (40,2) = possible => 5
                (25,12) (25,9) (25,6) (25,2) = possible => 4
                (19,9) (19,6) (19,2) = possible => 3
                (12,2) = possible => 1
                (9,2) = possible => 1
                (6,2) = possible => 1
                (40,25) (25,19) (19,12) (12,9) (12,6) (9,6) = not possible
                so, the answer will be 5+4+3+1+1+1=15*/
                    // brute force sol (time complexity = O(n^2), space complexity = O(1))
                        /*int arr[]={40,25,19,12,9,6,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int count=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            for(int j=i+1;j<size;j++){ // time complexity = O(n)
                                if(arr[i]>2*arr[j]) count++;
                            }
                        }
                        cout<<"No. of reverse pairs: "<<count;*/
                    // better sol using merge sort (time complexity = O(2nlogn), space complexity = O(n))
                        /*vector <int> arr={40,25,19,12,9,6,2};
                        int size=arr.size();
                        cout<<"No. of reverse pairs: "<<Divv(arr,0,size-1);*/
            // 12. maximum product subarray in an array
                // brute force sol (time complexity = O(n^3), space complexity = O(1))
                    /*int arr[]={2,3,-2,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int maxproduct=INT_MIN;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            int product=1;
                            for(int k=i;k<=j;k++) product*=arr[k]; // time complexity = O(n)
                            maxproduct=max(maxproduct,product);
                        }
                    }
                    cout<<"Max product of subarray: "<<maxproduct;*/
                // better sol (time complexity = O(n^2), space complexity = O(1))
                    /*int arr[]={2,3,-2,4};
                    int size=sizeof(arr)/sizeof(arr[0]);
                    int maxproduct=INT_MIN;
                    for(int i=0;i<size;i++){ // time complexity = O(n)
                        int product=1;
                        for(int j=i;j<size;j++){ // time complexity = O(n)
                            product*=arr[j];
                            maxproduct=max(maxproduct,product);
                        }
                    }
                    cout<<"Max product of subarray: "<<maxproduct;*/
                // optimal sol 1 uses modified kadane's algorithm (time complexity = O(n), space complexity = O(1))
                // optimal sol 2 most intuitive and must tell in place kadane's algorithm in iterviews completely observation based (time complexity = O(n), space complexity = O(1))
                    /*if array has:
                    1. all positives => max product = sum of all elements
                    2. even negatives => max product = sum of all elements
                    3. odd negatives => max product = max(prefixproduct,suffixproduct) => uses removal of one -ve 
                    4. any zero => max product = max(subarr1,subarr2,......subarrn) subarr1 is from starting to 1st occurence of 0 then subarr2 is from (first occurence of 0 + 1) to second occurence of 0*/
                        /*int arr[]={2,3,-2,4};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int maxproduct=INT_MIN;
                        int prefixproduct=1;
                        int suffixproduct=1;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(prefixproduct==0) prefixproduct=1;
                            if(suffixproduct==0) suffixproduct=1;
                            prefixproduct*=arr[i];
                            suffixproduct*=arr[size-(i+1)];
                            maxproduct=max(maxproduct, max(prefixproduct,suffixproduct));
                        }
                        cout<<"Max product of subarray: "<<maxproduct;*/

// binary search 
    /*1. A searching algorithm in a limited search space
        2. Dictionary can be a real life example
        3. it is always applicable when to search in a "sorted" search space
        4. overflow case: if we have search space from 0 to INT_MAX(max integer value that can be store in int datatype)
                        so when continous trimming if comes to a point where low==high
                        then int mid=(low+high)/2 = (INT_MAX+INT_MAX)/2 = (2*INT_MAX)/2 
                        => 2*INT_MAX can not be stored in any int datatype before performing a division by 2
                        hence to solve this overflow condition:
                        1. use long long datatype for finding mid
                        2. if we are very much sure that our search space is between 0 to INT_MAX
                            so if mid is at INT_MAX, still we don't need long long datatype
                            instead we can write mid=low+((high-low)/2) 
                            which is just similar to (low+high)/2 as;
                            => low + ((high-low)/2)
                            => (2low + high - low)/2
                            => (low + high)/2
                            so in overflow case it will be execute as INT_MAX + ((INT_MAX-INT_MAX)/2)
                            => INT_MAX + 0/2
                            => INT_MAX + 0 = INT_MAX
                            it is only valid if the search space is till INT_MAX not beyond that*/
        // on 1D arrays (time complexity = O(log base2 n))
            // 1. search element in array
                // iterative code 
                    /*int arr[]={3,4,6,7,9,12,16,17};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int target=16, low=0, high=size-1;
                        while(low<=high){ // time complexity = O(logn)
                            int mid=(low+high)/2;
                            if(arr[mid]==target){
                                cout<<mid;
                                break;
                            }
                            else if(target>arr[mid]) low=mid+1;
                            else high=mid-1;
                        }
                        if(low>high) cout<<"Target not found";*/
                // recursive code
                    /*int arr[]={3,4,6,7,9,12,16,17};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int target=16;
                        int result=binarySearch(arr,0,size-1,target);
                        if(result==-1) cout<<"Target not found";
                        else cout<<result;*/
            // 2. lower bound
                /*1. smallest index (ind) of array such that arr[ind] >= element
                    2. array must have to be sorted for lower bound to be implemented
                    3. eg, 3,5,8,15,19
                        if element=8, lowerbound=2
                        if element=9, lowerbound=3
                        if element=16, lowerbound=4
                        if element=20, lowerbound=5(hypothetical last index or size of the array)*/
                    // linear approach (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={1,2,3,3,7,8,9,9,9,11};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int element=11;
                            int flag=0;
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if(arr[i]>=element){
                                    cout<<"Lower bound: "<<i;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0) cout<<"Lower bound: "<<size;*/
                    // binary approarch (time complexity = O(logn), space complexity = O(1))
                        /*int arr[]={1,2,3,3,7,8,9,9,9,11};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int element=11;
                            int lowerbound=size;
                            int low=0, high=size-1;
                            while(low<=high){ //time complexity = O(logn)
                                int mid=(low+high)/2;
                                if(arr[mid]>=element){
                                    lowerbound=mid;
                                    high=mid-1;
                                }
                                else low=mid+1;
                            }
                            cout<<"Lower bound: "<<lowerbound;*/
                    // predefined function
                        /*int arr[]={1,2,3,3,7,8,9,9,9,11};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            // int lowerbound=lower_bound(vec.begin(),vec.end(),element)-vec.begin()
                            int lowerbound=lower_bound(arr,arr+size,11)-arr;
                            cout<<"Lower bound: "<<lowerbound<<endl;
                                        // or
                            int *lb=lower_bound(arr,arr+size,11); // returns iterator
                            cout<<"Lower bound: "<<lb-arr<<endl;
                            // between limited search space (for eg, from ind 2 to 6)
                            int l=lower_bound(arr+2,arr+7,10)-(arr+2);
                            cout<<"Lower bound: "<<l;*/
            // 3. upper bound
                /*1. smallest index (ind) of array such that arr[ind] > element
                    2. array must be sorted in order to implement upper bound
                    3. eg, 2,3,6,7,8,8,11,11,11,12
                        if element=6, upperbound=3
                        if element=11, upperbound=9
                        if element=12, upperbound=10(hypothetical index or size)
                        if element=0, upperbound=0(first index)*/
                    // linear approach (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={2,3,6,7,8,8,11,11,11,12};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int element=11;
                            int flag=0;
                            for(int i=0;i<size;i++){
                                if(arr[i]>element){
                                    cout<<"Upper bound: "<<i;
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==0) cout<<"Upper bound: "<<size;*/
                    // binary approach (time complexity = O(logn), space complexity = O(1))
                        /*int arr[]={2,3,6,7,8,8,11,11,11,12};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int upperbound=size;
                            int element=11;
                            int low=0,high=size-1;
                            while(low<=high){ // time complexity = O(log base 2 n)
                                int mid=(low+high)/2;
                                if(arr[mid] > element){
                                    upperbound=mid;
                                    high=mid-1;
                                }
                                else low=mid+1;
                            }
                            cout<<"Upper bound: "<<upperbound;*/
                    // predefined function
                        /*int arr[]={2,3,6,7,8,8,11,11,11,12};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            // int upperbound=upper_bound(vec.begin(),vec.end(),element)-vec.begin()
                            int upperbound=upper_bound(arr,arr+size,6)-arr;
                            cout<<"Upper bound: "<<upperbound<<endl;
                                            // or
                            int *up=upper_bound(arr,arr+size,11); // returns the iterator
                            cout<<"Upper bound: "<<up-arr<<endl;
                            // between specific search space (for eg, from index 2 to 6)
                            int u=upper_bound(arr+2,arr+7,8)-(arr+2);
                            cout<<"Upper bound: "<<u;*/
            // 4. search inserted position
                /*a sorted array of distinct value is given and a target value is given we have to find 
                    where to place this target value in the array
                    for eg, arr = 1,2,4,7 and target = 6
                    so answer will be 3rd index as
                    if we place 6 at 3rd index it will be 1,2,4,6,7 which is balanced array
                    NOTE: if target is already present in array return that index
                          if it is not then determine the index where it would be inserted in array to maintain order of array*/
                    // lower bound approach
                        /*int arr[]={1,2,4,7};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int target=6;
                            int ans=size;
                            int low=0,high=size-1;
                            while(low<=high){
                                int mid=(low+high)/2;
                                if(arr[mid]==target){
                                    ans=mid;
                                    break;
                                }
                                else if(arr[mid]>target){
                                    ans=mid;
                                    high=mid-1;
                                }
                                else low=mid+1;
                            }
                            cout<<ans;*/
            // 5. floor in sorted array
                /*floor is the largest number in the array which is >= element
                        eg, 10,20,30,40,50
                            floor of 25 is 20 as 20<=25 and 20 is the largest in the array that satisfies this condition
                            as 10 is also <= 25 and 20 is also <= 25
                            but 20 > 10 hence floor(25) is 20*/
                    /*int arr[]={10,20,30,40,50};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int element=25;
                        int floor=-1;
                        int low=0, high=size-1;
                        while(low<=high){
                            int mid=(low+high)/2;
                            if(arr[mid]<=element){
                                floor=arr[mid];
                                low=mid+1;
                            }
                            else high=mid-1;
                        }
                        cout<<"Floor: "<<floor;*/
            // 6. ceil in sorted array
                /*ceil is the smallest number in the array which is >= element
                        eg, 10,20,30,40,50
                            ceil of 25 is 30 as 30>=25 and 30 is the smallest in the array that satisfies the condition
                            as 40,50 are also >= 25 and 30 is also >= 25
                            but 30 < 40 and 50 hence ceil(25) is 30
                            => ceil is actually the lower bound*/
                    /*int arr[]={10,20,30,40,50};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int element=25;
                        int ceil=-1;
                        int low=0, high=size-1;
                        while(low<=high){
                            int mid=(low+high)/2;
                            if(arr[mid]>=element){
                                ceil=arr[mid];
                                high=mid-1;
                            }
                            else low=mid+1;
                        }
                        cout<<"Ceil: "<<ceil;*/
            // 7. find first and last occurence of element
                // linear approach (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={2,4,6,8,8,8,11,13};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int firstocc=-1, lastocc=-1;
                        int element=15;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(arr[i]==element){
                                if(firstocc==-1) firstocc=i;
                                lastocc=i;
                            }
                        }
                        cout<<"First occurence: "<<firstocc<<endl;
                        cout<<"Last occurence: "<<lastocc;*/
                // lower bound and upper bound approrach (time complexity = 2 * O(log base 2 n), space complexity = O(1))
                    /*int arr[]={2,4,6,8,8,8,11,13};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int element=8;
                        int firstocc=-1, lastocc=-1;
                        int low=0, high=size-1;
                        // first occurence
                        while(low<=high){ // time complexity = O(logn)
                            int mid=(low+high)/2;
                            if(arr[mid]>=element){
                                firstocc=mid;
                                high=mid-1;
                            }
                            else low=mid+1;
                        }
                        low=0, high=size-1;
                        // last occurence
                        while(low<=high){ // time complexity = O(logn)
                            int mid=(low+high)/2;
                            if(arr[mid]>element){
                                lastocc=mid;
                                high=mid-1;
                            }
                            else low=mid+1;
                        }
                        if(firstocc==size || arr[firstocc]!=element){
                            cout<<"First occurence: -1"<<endl;
                            cout<<"Last occurence: -1";
                        }
                        else{
                            cout<<"First occurence: "<<firstocc<<endl;
                            if(lastocc==-1) cout<<"Last occurence: "<<size-1;
                            else cout<<"Last occurence: "<<lastocc-1;
                        }*/
                // simple binary approach (time complexity = 2 * O(log base 2 n), space complexity = O(1))
                    /*int arr[]={2,4,6,8,8,8,11,13};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int element=8;
                        // first occurence
                        int firstocc=-1;
                        int low=0, high=size-1;
                        while(low<=high){ // time complexity = O(logn)
                            int mid=(low+high)/2;
                            if(arr[mid]==element){
                                firstocc=mid;
                                high=mid-1;
                            }
                            else if(arr[mid]<element) low=mid+1;
                            else high=mid-1;
                        }
                        cout<<"First occurence: "<<firstocc<<endl;
                        // last occurence
                        int lastocc=-1;
                        if(firstocc != -1){
                            low=0, high=size-1;
                            while(low<=high){ // time complexity = O(logn)
                                int mid=(low+high)/2;
                                if(arr[mid]==element){
                                    lastocc=mid;
                                    low=mid+1;
                                }
                                else if(arr[mid]>element) high=mid-1;
                                else low=mid+1;
                            }
                        }
                        cout<<"Last occurence: "<<lastocc;*/
            // 8. find frequency of an element in a sorted array
                // linear approach (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={1,1,1,2,2,3,3}; 
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int element=3;
                        int count=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(arr[i]==element) count++;
                        }
                        cout<<"Total occurences: "<<count;*/
                // lower bound and upper bound approach (time complexity = 2 * O(log base 2 n), space complexity = O(1))
                    /*int arr[]={1,1,1,2,2,3,3};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int element=2;
                        // first occurence or lower bound
                        int firstocc=-1;
                        int low=0, high=size-1;
                        while(low<=high){
                            int mid=(low+high)/2;
                            if(arr[mid]>=element){
                                firstocc=mid;
                                high=mid-1;
                            }
                            else low=mid+1;
                        }
                        // last occurence or upper bound - 1
                        int lastocc=-1;
                        low=0, high=size-1;
                        while(low<=high){
                            int mid=(low+high)/2;
                            if(arr[mid]>element){
                                lastocc=mid;
                                high=mid-1;
                            }
                            else low=mid+1;
                        }
                        if(firstocc==size || arr[firstocc]!=element) cout<<"Total occurences: 0";
                        else{
                            if(lastocc==-1) lastocc=size-1;
                            else lastocc--; // last occurence
                            // finding frequency
                            cout<<"Total occurences: "<<lastocc-firstocc+1;
                        }*/
                // simple binary approach (time complexity = 2 * O(log base 2 n), space complexity = O(1))
                    /*int arr[]={1,1,1,2,2,3,3};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int element=3;
                        // first occurence
                        int firstocc=-1;
                        int low=0, high=size-1;
                        while(low<=high){ // time complexity = O(logn)
                            int mid=(low+high)/2;
                            if(arr[mid]==element){
                                firstocc=mid;
                                high=mid-1;
                            }
                            else if(arr[mid]<element) low=mid+1;
                            else high=mid-1;
                        }
                        // last occurence
                        int lastocc=-1;
                        if(firstocc == -1) cout<<"Total occurences: 0";
                        else{
                            low=0, high=size-1;
                            while(low<=high){ // time complexity = O(logn)
                                int mid=(low+high)/2;
                                if(arr[mid]==element){
                                    lastocc=mid;
                                    low=mid+1;
                                }
                                else if(arr[mid]<element) low=mid+1;
                                else high=mid-1;
                            }
                            cout<<"Total occurences: "<<lastocc-firstocc+1;
                        }*/
            // 9. search element in a rotated sorted array with distinct elements, answer should be the index of element
                /*eg, 4,5,6,7,0,1,2 is the rotated sorted array
                    as 0,1,2 should be in the left side while 4,5,6,7 should be the afterwards of 0,1,2
                    in this we have to search an element = 0 so the answer = 4 (0 is +nt at 4th index)
                    if element = 3 answer = -1(as 3 is not present in the array)*/
                    // linear approach (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={4,5,6,7,0,1,2};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int element=0;
                            int flag=0;
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if(arr[i]==element){
                                    cout<<i;
                                    flag++;
                                }
                            }
                            if(flag==0) cout<<-1;*/
                    // binary approach (time complexity = O(log base 2 n), space complexity = O(1))
                        /*int arr[]={4,5,6,7,0,1,2};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int element=0;
                            int flag=0;
                            int low=0, high=size-1;
                            while(low<=high){ // time complexity = O(logn)
                                int mid=(low+high)/2;
                                if(arr[mid]==element){
                                    cout<<mid;
                                    flag++;
                                    break;
                                }
                                // left half sorted
                                if(arr[low]<=arr[mid]){
                                    if(arr[low]<=element && element<arr[mid]) high=mid-1;
                                    else low=mid+1;
                                }
                                // right half sorted
                                else{
                                    if(arr[mid]<element && element<=arr[high]) low=mid+1;
                                    else high=mid-1;
                                }
                            }
                            if(flag==0) cout<<-1;*/
            // 10. search element in rotated sorted array with duplicate elements, answer should be if it exists or not (yes/no)
                /*eg 3,1,2,3,3,3,3 is a sorted rotated array
                    in this if we apply the logic of finding element in a sorted rotated array of distinct elements
                    we might face ambiguity to find which half is sorted 
                    as at one point arr[low]=arr[mid]=arr[high]
                    then the condition to check the which is sorted 
                    1. for left half => arr[low]<=arr[mid]
                    2. for right half => arr[mid]<=arr[high]
                    not worked as arr[low]=arr[mid]=arr[high]=3(in the above example)
                    which shows 
                    1. for left half => 3<=3
                    2. for right half => 3<=3
                    now it is difficult to understand which half is sorted
                    so to overcome this ambiguity just trimming down the problem by shrinking the array is the solution
                    until we get to a point where we can identify which half is sorted 
                    just by increasing low as low+1 and decreasing high as high-1*/
                    // linear approach (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={3,1,2,3,3,3,3};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int element=1;
                            int flag=0;
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if(arr[i]==element){
                                    cout<<"Yes";
                                    flag++;
                                    break;
                                }
                            }
                            if(flag==0) cout<<"No";*/
                    // binary approach (time complexity = O(n) in worst case, space complexity = O(1))
                        /*int arr[]={3,1,2,3,3,3,3};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int element=1;
                            int flag=0;
                            int low=0, high=size-1;
                            while(low<=high){ // time complexity = O(n) in worst case when always overcome ambiguity case executes
                                int mid=(low+high)/2;
                                if(arr[mid]==element){
                                    cout<<"Yes";
                                    flag++;
                                    break;
                                }
                                // overcome ambiguity
                                if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                                    low++;
                                    high--;
                                    continue;
                                }
                                // left half sorted
                                else if(arr[low]<=arr[mid]){
                                    if(arr[low]<=element && element<arr[mid]) high=mid-1;
                                    else low=mid+1;
                                }
                                // right half sorted
                                else{
                                    if(arr[mid]<element && element<=arr[high]) low=mid+1;
                                    else high=mid-1;
                                }
                            }
                            if(flag==0) cout<<"No";*/
            // 11. smallest element in rotated sorted array containing unique elements
                // linear approach (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={4,5,6,7,0,1,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int min=arr[0];
                        for(int i=1;i<size;i++){ // time complexity = O(n)
                            if(arr[i]<min) min=arr[i];
                        }
                        cout<<"Minimum: "<<min;*/
                // binary approach (time complexity = O(log base 2 n), space complexity = O(1))
                    /*eg; 4,5,1,2,3
                        here right half is sorted so pick the amllest element from right half i.e., arr[mid]
                        and move high to mid-1 to check on the left half as well
                        as sorted half may or may not contain the answer
                        similarly if laft half is sorted, pick the smallest element from left i.e., arr[low]
                        and move low to mid+1 to check on the right half as well*/
                        /*int arr[]={4,5,6,7,0,1,2};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int Min=INT_MAX;
                            int low=0, high=size-1;
                            while(low<=high){ // time complexity = O(logn)
                                int mid=(low+high)/2;
                                // if the search space is already sorted then arr[low] is the minimum for sure
                                if(arr[low]<=arr[high]){
                                    Min=min(Min,arr[low]);
                                    break;
                                }
                                // left half sorted
                                if(arr[low]<=arr[mid]){
                                    Min=min(Min,arr[low]);
                                    low=mid+1;
                                }
                                // right half sorted
                                else{
                                    Min=min(Min,arr[mid]);
                                    high=mid-1;
                                }
                            }
                            cout<<"Minimum: "<<Min;*/
            // 12. smallest element in a rotated sorted array containing duplicate elements
                // linear approach (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={4,4,4,5,6,6,7,0,0,1,2,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int min=arr[0];
                        for(int i=1;i<size;i++){ // time complexity = O(n)
                            if(arr[i]<min) min=arr[i];
                        }
                        cout<<"Minimum: "<<min;*/
                // binary approach (time complexity = O(n) in worst case, space complexity = O(1))
                    /*int arr[]={4,4,4,5,6,6,7,0,0,1,2,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int Min=INT_MAX;
                        int low=0, high=size-1;
                        while(low<=high){ // time complexity = O(n) in worst case and O(logn) in average cases
                            int mid=(low+high)/2;
                            // if search space is already sorted
                            if(arr[low]<=arr[high]){
                                Min=min(Min,arr[low]);
                                break;
                            }
                            // overcome ambiguity
                            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                                low++;
                                high--;
                                continue;
                            }
                            // left half sorted
                            if(arr[low]<=arr[mid]){
                                Min=min(Min,arr[low]);
                                low=mid+1;
                            }
                            // right half sorted
                            else{
                                Min=min(Min,arr[mid]);
                                high=mid-1;
                            }
                        }
                        cout<<"Minimum: "<<Min;*/ 
            // 13. find how many times a rotated sorted array containing unique elements, is rotated
                /*eg, 3,4,5,1,2 answer = 3 times
                    as ideal array should be 1,2,3,4,5
                    here 3,4,5(3 elements) are placed in front rather than 1,2
                    so the answer should be 3 times which is nothing but the index of minimum element in the array*/
                    // linear approach (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={3,4,5,1,2};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int Min=arr[0];
                            int times=0;
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if(arr[i]<=Min){
                                    Min=arr[i];
                                    times=i;
                                }
                            }
                            cout<<"No. of times array is rotated: "<<times;*/
                    // binary approach (time complexity = O(log base 2 n), space complexity = O(1))
                        /*int arr[]={3,4,5,1,2};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int times=-1;
                            int Min=INT_MAX;
                            int low=0, high=size-1;
                            while(low<=high){ // time complexity = O(logn)
                                int mid=(low+high)/2;
                                // search space is already sorted
                                if(arr[low]<=arr[high]){
                                    if(arr[low]<Min){
                                        times=low;
                                        Min=arr[low];
                                    }
                                    break;
                                }
                                // left half sorted
                                if(arr[low]<=arr[mid]){
                                    if(arr[low]<Min){
                                        times=low;
                                        Min=arr[low];
                                    }
                                    low=mid+1;
                                }
                                // right half sorted
                                else{
                                    if(arr[mid]<Min){
                                        times=mid;
                                        Min=arr[mid];
                                    }
                                    high=mid-1;
                                }
                            }
                            cout<<"No. of times array is rotated: "<<times;*/
            // 14. find how many times a rotated sorted array containing duplicate elements, is rotated
                // linear approach (time complexity = O(n), space complexity = O(1))
                    /*int arr[]={3,3,3,4,5,5,1,1,1,2,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int Min=arr[0];
                        int times=-1;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(arr[i]<Min){
                                times=i;
                                Min=arr[i];
                            }
                        }
                        cout<<"No. of times array is rotated: "<<times;*/
                // binary approach (time complexity = O(n) in worst case and O(log base 2 n) in average case, space complexity = O(1))
                    /*int arr[]={3,3,3,4,5,5,1,1,1,2,2};
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int times=-1;
                        int Min=INT_MAX;
                        int low=0, high=size-1;
                        while(low<=high){ // time complexity = O(logn) in average cases and O(n) in worst case
                            int mid=(low+high)/2;
                            // search space already sorted
                            if(arr[low]<=arr[high]){
                                if(arr[low]<Min){
                                    Min=arr[low];
                                    times=low;
                                }
                                break;
                            }
                            // overcome ambiguity
                            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                                low++;
                                high--;
                                continue;
                            }
                            // left half sorted
                            if(arr[low]<=arr[mid]){
                                if(arr[low]<Min){
                                    Min=arr[low];
                                    times=low;
                                }
                                low=mid+1;
                            }
                            // right half sorted
                            else{
                                if(arr[mid]<Min){
                                    Min=arr[mid];
                                    times=mid;
                                }
                                high=mid-1;
                            }
                        }
                        cout<<"No. of times array is rotated: "<<times;*/
            // 15. find the element appears only once in a sorted array
                /*eg, 1,1,2,2,3,3,4,5,5,6,6 
                    all the elements will be appearing twice except one element
                    we have to find that element
                    in the above array, answer=4
                    as if we look we find (1,1),(2,2),(3,3),4,(5,5),(6,6)
                    here before the answer the pairs are having (evenindex, oddindex)
                    and after the answer the pairs have (oddindex, evenindex)
                    so if we are standing at arr[mid] and arr[mid+1]==arr[mid] or arr[mid-1]==arr[mid]
                    then check which half to eliminated:
                    1. left half eliminate 
                        if arr[mid-1] has even index and arr[mid] has odd index => (even,odd)
                        => element is on the right side
                    2. right half eliminate 
                        if arr[mid] has odd index and arr[mid+1] has even index => (odd,even)
                        => element is on the left side*/
                    // brute force sol (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={1,1,2,2,3,3,4,5,5,6,6};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            if(size==1) cout<<"Element appears once: "<<arr[0];
                            else{
                                for(int i=0;i<size;i++){ // time complexity = O(n)
                                    if(i==0){
                                        if(arr[i] != arr[i+1]) cout<<"Element appears once: "<<arr[i];
                                    }
                                    else if(i==size-1){
                                        if(arr[i-1] != arr[i]) cout<<"Element appears once: "<<arr[i];
                                    }
                                    else{
                                        if(arr[i-1]!=arr[i] && arr[i]!=arr[i+1]) cout<<"Element appears once: "<<arr[i];
                                    }
                                }
                            }*/
                    // better sol using binary approach (time complexity = O(log base 2 n), space complexity = O(1))
                        /*int arr[]={1,1,2,2,3,3,4,5,5,6,6};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            // if array has only one element
                            if(size==1) cout<<"Element appears once: "<<arr[0];
                            // at first index
                            else if(arr[0] != arr[1]) cout<<"Element appears once: "<<arr[0];
                            // at last index
                            else if(arr[size-2] != arr[size-1]) cout<<"Element appears once: "<<arr[size-1];
                            // at any middle index
                            else{
                                int low=1, high=size-2; // trimming the first and last elements
                                while(low<=high){ // time complexity = O(logn)
                                    int mid=(low+high)/2;
                                    if(arr[mid-1]!=arr[mid] && arr[mid]!=arr[mid+1]){
                                        cout<<"Element appears once: "<<arr[mid];
                                        break;
                                    }
                                    // left half eliminate
                                    else if((mid%2==1 && arr[mid-1]==arr[mid]) || (mid%2==0 && arr[mid]==arr[mid+1])) low=mid+1;
                                    // right half eliminate
                                    else high=mid-1;
                                }
                            }*/
            // 16. find peak element
                /*arr[i-1] <arr[i]> arr[i+1]
                    here arr[i] = peak element
                    eg1; 1,2,3,4,5,6,7,8,5,1 => here peak element=8
                    eg2; 1,2,1,3,5,6,4 => here peak element=2,6 so answer can be contain any one of them
                    eg3; 1,2,3,4,5 => here no peak element but we have told to assume -infinity to both the sides
                                   => -inf,1,2,3,4,5,-inf => peak element=5(as 4 < 5 > -inf)
                    eg4; 5,4,3,2,1 => here again no peak element
                                   => -inf,5,4,3,2,1,-inf => peak element=5(as -inf < 5 > 4)*/
                    // linear approach (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={1,2,3,4,5,6,7,8,5,1};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if((i==0 || arr[i-1]<arr[i]) // check left element i.e., arr[i-1]
                                                &&
                                   (i==size-1 || arr[i]>arr[i+1])) // check right element i.e., arr[i+1]
                                cout<<"Peak element: "<<arr[i];
                            }*/
                    // binary approach for only one peak (time complexity = O(log base 2 n), space complexity = O(1))
                        /*int arr[]={1,2,3,4,5,6,7,8,5,1};
                            int size=sizeof(arr)/sizeof(arr[0]);
                            if(size==1) cout<<"Peak element: "<<arr[0]; // if array has only one element
                            else if(arr[0]>arr[1]) cout<<"Peak element: "<<arr[0]; // if array is in decreasing order
                            else if(arr[size-2]<arr[size-1]) cout<<"Peak element: "<<arr[size-1]; // if array is in increasing order
                            else{ // if array has both increasing as well as decreasing order
                                int low=1, high=size-2;
                                while(low<=high){ // time complexity = O(logn)
                                    int mid=(low+high)/2;
                                    if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){ // peak is at mid
                                        cout<<"Peak element: "<<arr[mid];
                                        break;
                                    }
                                    else if(arr[mid]<arr[mid+1]) low=mid+1; // peak is on right side
                                    else high=mid-1; // peak is on left side
                                }
                            }*/
                    // binary approach for multiple peaks (time complexity = O(log base 2 n), space complexity = O(1))
                        /*eg 1,5,1,2,4 => here mid=1 => 5 > 1 < 2
                            => so none of the three cases of binary search will execute in this situation
                            => so we have 2 options 
                            1. add extra else and move in any direction as both the directions can have peaks
                            2. eliminate a previous else and just either on the left or the right side*/
                            /*int arr[]={1,2,3,4,5,6,7,8,5,1};
                                int size=sizeof(arr)/sizeof(arr[0]);
                                if(size==1) cout<<"Peak element: "<<arr[0]; // if array has only one element
                                else if(arr[0]>arr[1]) cout<<"Peak element: "<<arr[0]; // if array is in decreasing order
                                else if(arr[size-2]<arr[size-1]) cout<<"Peak element: "<<arr[size-1]; // if array is in increasing order
                                else{ // if array has both increasing as well as decreasing order
                                    int low=1, high=size-2;
                                    while(low<=high){ // time complexity = O(logn)
                                        int mid=(low+high)/2;
                                        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){ // peak is at mid
                                            cout<<"Peak element: "<<arr[mid];
                                            break;
                                        }
                                        else if(arr[mid]<arr[mid+1]) low=mid+1; // peak is on right side
                                        else high=mid-1; // peak is on left side or can be right side => moving left side
                                            // or
                                        // else low=mid+1; // => moving right side
                                    }
                                }*/
        // on answers
            // 1. find sqaure root of an integer
                // linear approach (time complexity = O(number) in worst/rare case, space complexity = O(1))
                    /*int num=25;
                    int sq=1;
                    for(int i=1;i<=num;i++){ // time complexity = O(num)
                        if(i*i<=num) sq=i;
                        else break;
                    }
                    cout<<"Square root: "<<sq;*/
                // binary approach (time complexity = O(log base 2 n), space complexity = O(1))
                    /*int num=28;
                    int low=1, high=num;
                    while(low<=high){ // time complexity = O(logn)
                        long long mid=(low+high)/2;
                        long long sq=mid*mid;
                        if(sq<=num) low=mid+1;
                        else high=mid-1;
                    }
                    cout<<"Square root: "<<high;*/
            // 2. find n-th root of an integer till the 5 decimal points
                // binary approach (time complexity = O(log base 2(num*10 to the power d)*power), space complexity = O(1))
                    /*since if we find answer to 1 decimal point every iteration i.e., from 1 to 2 contains 10
                    numbers (1.1,1.2,1.3,......,1.9,2)
                    => time complexity = (log(num*10))
                    so if we want d decimal places answer 
                    => time complexity = O(log(num*10 to the power d))
                    for answer should be in 5 decimal points
                    the difference between high and low i.e., high-low > 10 to the power -6 => 1e power of -6
                    high-low i.e., the difference is known as epsilon*/
                        /*double num=8;
                        double root=3;
                        double low=1, high=num;
                        double eps=1e-6;
                        while((high-low) > eps){ // time complexity = O(log(num * 10 to the power of decimalplacewewantinanswer)) => O(log(num * 10 to the power eps-1))
                            double mid=(low+high)/2.0;
                            double value=1.0;
                            for(int i=1;i<=root;i++) value=value*mid; // time complexity = O(root)
                            if(value<num) low=mid;
                            else high=mid;
                        }
                        // since high-low is very very small at the end => high is approx equal to low we can either print high or print low
                        cout<<"n-th root: "<<low<<endl; 
                        cout<<"n-th root: "<<high<<endl;
                        // checking by maths predefined function of decimal sqaure root
                        cout<<"n-th root: "<<pow(num,(double)(1.0/(double(root))));*/
            // 3. koko eating bananas 
                /*we have given an array of piles of bananas and the max hour that koko can take
                we need to find min integer k so that koko can eat all piles of bananas within given hours
                for eg, pilesofbananas = 3,6,7,11 and hours=8
                now if we assume 
                1. k=2 bananas per hour 
                then, time taken for for eating piles of bananas will be 2(1.5)hr, 3hr, 4(3.5)hr, 6(5.5)hr
                => total time = 2+3+4+6=15hrs > 8hrs(given)
                2. k=3 bananas per hour
                then time taken will be 1hr, 2hr, 3(2.33)hr, 4(3.67)hr
                => total time = 1+2+3+4=10hrs > 8hrs(given)
                3. k=4 bananas per hour
                then time taken will be 1(0.75)hr, 2(1.5)hr, 2(1.75)hr, 3(2.75)hr
                => total time = 1+2+2+3=8hrs == 8hrs(given)
                so, answer k will be 4*/
                    // linear approach (time complexity = O(max of arrelements * n), space complexity = O(1))
                        /*int arr[]={3,6,7,11};
                        int h=8;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int k=0;
                        for(int i=1;i<=arr[size-1];i++){ // time complexity = O(max(arrelements))
                            int time=0;
                            for(int j=0;j<size;j++) time += ceil((double)arr[j]/(double)i); // time complexity = O(n)
                            if(time <= h){
                                k=i;
                                break;
                            }
                        }
                        cout<<k<<" bananas per hour";*/
                    // binary approach (time complexity = O(n * log(max of arr elements)), space complexity = O(1))
                        /*int arr[]={3,6,7,11};
                        int h=8;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int low=1, high=arr[size-1];
                        while(low<=high){ // time complexity = O(log maxofarrelements)
                            int mid=(low+high)/2;
                            int time=0;
                            for(int i=0;i<size;i++) time += ceil((double)arr[i]/(double)mid); // time complexity = O(n)
                            if(time<=h) high=mid-1;
                            else low=mid+1;
                        }
                        cout<<low<<" bananas per hour";*/
            // 4. minimum days to make bouquets
                /*we have given no of bouquets we need to make (m), and the number of flowers that each bouquet 
                should contain (k), and an array of blooming day of flowers
                note that the k should be adjacent no of flowers
                now for eg, bloom day = 7,7,7,7,13,11,12,7 m=2 k=3
                1. if we wait for 7 days then, 7,7,7,7,7 can be bloomed but 13,11,12 cannot be bloomed
                so it is like y,y,y,y,n,n,n,y (y=yes, n=no) in array
                => y,y,y = one bouquet
                but y,n,n,n,y cannot be consider to make second bouquet
                2. if we wait for 12 days then, 7,7,7,7,11,12,7 can be bloomed but 13 cannot be bloomed
                so it is y,y,y,y,n,y,y,y in array
                => first three y,y,y = one bouquet
                last three y,y,y = second bouquet
                hence the answer will be 12
                3. 11 days wait will also not possible to make 2 bouquets of 3 adjacent flowers
                also in some cases like 1,2,10,4,3
                here if we wait for the max days i.e., 10
                still we are not able to make 2 bouquets of 3 adjacent flowers after taking all the flowers too
                in such cases answer should be -1*/
                    // linear approach (time complexity = O(n * difference(max,min)), space complexity = O(1))
                        /*int arr[]={7,7,7,7,12,11,13,7};
                        int m=2, k=3;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int maxx=arr[0], minn=arr[0];
                        for(int i=0;i<size;i++){
                            if(arr[i]>maxx) maxx=arr[i];
                            if(arr[i]<minn) minn=arr[i];
                        }
                        if((m*k)>size) cout<<-1;
                        else{
                            for(int i=minn;i<=maxx;i++){ // time complexity = O(difference b/w maxelement and minelement)
                                int cnt=0;
                                int bouquet=0;
                                for(int j=0;j<size;j++){ // time complexity = O(n)
                                    if(arr[j]<=i){
                                        cnt++;
                                        if(cnt==k){
                                            bouquet++;
                                            cnt=0;
                                        }
                                    }
                                    else cnt=0;
                                }
                                if(bouquet>=m){
                                    cout<<"Day: "<<i;
                                    break;
                                }
                            }
                        }*/
                    // binary approach (time complexity = O(n * log(max-min)), space complexity = O(1))
                        /*int arr[]={7,7,7,7,12,11,13,7};
                        int m=2, k=3;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int minn=arr[0], maxx=arr[0];
                        for(int i=0;i<size;i++){
                            if(arr[i]<minn) minn=arr[i];
                            if(arr[i]>maxx) maxx=arr[i];
                        }
                        int low=minn, high=maxx;
                        if(m*k > size) cout<<-1;
                        else{
                            while(low<=high){ // time complexity = O(log(max-min))
                                int mid=(low+high)/2;
                                int cnt=0, bouquet=0;
                                for(int i=0;i<size;i++){ // time complexity = O(n)
                                    if(arr[i]<=mid){
                                        cnt++;
                                        if(cnt==k){
                                            bouquet++;
                                            cnt=0;
                                        }
                                    }
                                    else cnt=0;
                                }
                                if(bouquet>=m) high=mid-1;
                                else low=mid+1;
                            }
                            cout<<"Day: "<<low;
                        }*/
            // 5. smallest divisor giving a threshold value
                /*eg, 1,2,5,9 threshold=6
                now if, 
                1. div=4(say)
                    1/4 + 2/4 + 5/4 + 9/4 <= 6(threhsold) => not possible
                2. div=5(say)
                    1/5 + 2/5 + 5/5 + 9/5 <= 6 => possible
                3 similarly, div=6,7,8,..... => 
                note that we need to take the ceil value of the divsion answer (1/4 = 0.25 = ceil(0.25) = 1)*/
                    // linear approach (time complexity = O(n * max_element), space complexity = O(1))
                        /*int arr[]={1,2,5,9};
                        int threshold=6;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int maxx=0;
                        for(int i=0;i<size;i++) maxx=max(maxx,arr[i]);
                        if(threshold < size) cout<<"Not possible";
                        else{
                            for(int i=1;i<=maxx;i++){ // time complexity = O(maxelement)
                                int div=0;
                                for(int j=0;j<size;j++) div += ceil((double)arr[j]/(double)i); // time complexity = O(n)
                                if(div<=threshold){
                                    cout<<"Min div: "<<i;
                                    break;
                                }
                            }
                        }*/
                    // binary approach (time complexity = O(n * log(max_element)), space complexity = O(1))
                        /*int arr[]={1,2,5,9};
                        int threshold=6;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int maxx=0;
                        for(int i=0;i<size;i++) maxx=max(maxx,arr[i]);
                        if(threshold < size) cout<<"Not possible";
                        else{
                            int low=1, high=maxx;
                            while(low<=high){ // time complexity = O(log(maxelement))
                                int mid=(low+high)/2;
                                int div=0;
                                for(int i=0;i<size;i++) div += (arr[i]+mid-1)/mid; // time complexity = O(n)
                                if(div <= threshold) high=mid-1;
                                else low=mid+1;
                            }
                            cout<<"Min div: "<<low;
                        }*/
            // 6. least capacity to ship packages within a given days
                /*we have a ship that goes once in a day and an array of items that has to be shipped
                the elements of that array contains the weight of each items => 1,2,3,4,5,6,7,8,9,10
                also we are given days=5(say)
                now our task is to compute the minimum weight that the ship can take in order to package all the 
                items within 5 days
                for eg; 1,2,3,4,5,6,7,8,9,10 days=5(say) and if
                1. min weight or least capacity of ship = 100
                    then we can load all the items on the ship once
                    and the shipping is done in only 1 day
                    but we need to compute the minimum capacity => we need to decrease the weight
                    (=> b/w min and max weight of item)
                2. min weight = 10
                    we can load 1,2,3,4 in 1st day (but cannot 5,6,7,8,9,10)
                    then on second day we can load only 5 (cannot 6,7,8,9,10)
                    on third day we can load only 6, similarly
                    on fourth day we can load only 7
                    on fifth day we can load only 8
                    now still 9,10 are left => so min weight=10 is not possible => we need to increase the weight
                3. min weight = 15
                    on first day = 1,2,3,4,5
                    on second day = 6,7
                    on third day = 8
                    on fourth day = 9
                    on fifth day = 10
                    => min capacity = 15
                note that ship can load only adjacent items
                if capacity = 15 => we can load 6,7 not 6,9
                similarly, we can load only 8 not 7,8*/
                    // linear approach (time complexity = O(n * (sumofallelements-maxelement) => nearly O(n^2)), space complexity = O(1))
                        /*int arr[]={1,2,3,4,5,6,7,8,9,10};
                        int days=5;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int minn=0;
                        for(int i=0;i<size;i++) minn=max(minn,arr[i]); // minimum weight
                        int sumofweights=(size*(size+1))/2; // maximum weight
                        for(int i=minn;i<=sumofweights;i++){ // time complexity = O(sum-max) => near about O(n) if array is too large
                            int daycnt=1;
                            int load=0;
                            for(int j=0;j<size;j++){ // time complexity = O(n)
                                if(load+arr[j] <= i) load+=arr[j];
                                else{
                                    daycnt++;
                                    load=arr[j];
                                }
                            }
                            if(daycnt<=days){
                                cout<<"Least capacity: "<<i;
                                break;
                            }
                        }*/
                    // binary appraoch (time complexity = O(n * log(sum-max) => nearly O(n*logn)), space complexity = O(1))
                        /*int arr[]={1,2,3,4,5,6,7,8,9,10};
                        int days=5;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int minn=0;
                        for(int i=0;i<size;i++) minn=max(minn,arr[i]); // minimum capacity
                        int maxx=(size*(size+1))/2; // maximum capacity or maxx=accumulate(arr,arr+size,0) => works for any array not only for array of sequence(1 to n)
                        int low=minn, high=maxx;
                        while(low<=high){ // time complexity = O(log(sumofelements-maxelement))
                            int mid=(low+high)/2; // assuming capacity;
                            int dayno=1;
                            int load=0;
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if(load+arr[i] > mid){
                                    dayno++;
                                    load=arr[i];
                                }
                                else load+=arr[i];
                            }
                            if(dayno<=days) high=mid-1;
                            else low=mid+1;
                        }
                        cout<<"Least capacity: "<<low;*/
            // 7. find n-th missing number
                /*we have an array of increasing positive integers and n-th place 
                such as 2,3,4,7,11 and n=5
                now, if we see the maxx element is 11 => array must be be like 1,2,3,4,5,6,7,8,9,10,11
                now, 2,3,4,7,11 are present in the array
                here 1,5,6,8,9,10 are missing => new array
                in this new array we have to locate nth position i.e., 5(in this eg)
                in new array, 9 is at 5th place
                so the answer should be 9*/
                    // linear approach (time complexity = O(n), space complexity = O(1))
                        /*int arr[]={2,3,4,7,11};
                        int n=5;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            if(arr[i] <= n) n++;
                            else break;
                        }
                        cout<<"Missing number: "<<n;*/
                    // binary approach (time complexity = O(logn), space complexity = O(1))
                        /*in this approach normal binary search cannot be applied as no is not present in the array
                        also binary search on answers can also be not applied as we dont know the range
                        we can only identify the nearby two indices in between which the ans can lie
                        like in this eg, ans 9 will lie b/w 7 and 11
                        to do so 
                        1. we know that ideally the array should be 1 to n (n=11) in this case
                        2. if we write indices => 0 1 2 3 4 
                                       elements = 2 3 4 7 11
                        3. if we observe let say index 3, it has 7 but, ideally should have 4
                            => there are 3 numbers missing till 3rd index => 7-4
                        4. similarly if we take 4th index 
                            currently contain = 11, ideally contain = 5
                            missing numbers = 11-5 = 6 numbers
                        5. now writing all the missing numbers count along with their positions
                                index => 0 1 2 3 4
                             elements => 2 3 4 7 11
                              missing => 1 1 1 3 6
                        6. again if we observe, we are looking for 5th missing value
                            => it cannot be found till where the missing numbers are 1
                            => it is found somewhere the greater numbers are missing like 6
                            => it is found b/w 3 and 6 => 3 <= 5 >= 6*/
                            /*int arr[]={2,3,4,7,11};
                            int n=5;
                            int size=sizeof(arr)/sizeof(arr[0]);
                            int low=0, high=size-1;
                            while(low<=high){ // time complexity = O(logn)
                                int mid=(low+high)/2;
                                int missing=arr[mid]-(mid+1); // missing numbers count = 7 - (3+1) = 7-4 = 3
                                if(missing < n) low=mid+1;
                                else high=mid-1;
                            }
                            // now, we have high at 7 and low at 11
                            // missing=arr[high]-(high+1) => 7-(3+1) => 7-4 => 3
                            // more=n-missing => 5-3 => 2
                            // ans=arr[high]+more => 7+2 => 9
                            // so it can be written as 
                            // ans = arr[high]+(n-missing)
                            // ans = arr[high]+(n-(arr[high]-(high+1)))
                            //     = arr[high] + n - arr[high] + (high+1)
                            //     = n + high + 1
                            // so we have to return n + high + 1
                            cout<<"Missing number: "<<n+high+1;
                            // here low is pointing high+1 so following can also be wriiten
                            // cout<<"Missing number: "<<n+low;*/
        // on answers in the pattern to find minimum of maximum => min(max) or maximum of minimum => max(min)
            // 1. aggressive cows
                /*we have given the array of stalls and no of cows 
                each cow can go any of the stall 
                we need to find that the minimum distance between those two cows which is the maximum
                remember that the minimum distance will always be between two consecutive cows
                (2,3,4,5) => distance b/w 2 and 3 (consecutive) = 1 while 2 and 4 (non-consecutive) = 2
                which is always > 1
                now, eg 0,3,4,7,10,9 and cows=4
                1. let's place cows like
                        0 , 3 , 4 , 7 , 9 , 10
                        c1, c2, c3, c4
                    now, distance = 3,1,3 => min=1
                2. let's place them as 
                        0 , 3 , 4 , 7 , 9 , 10
                        c1,     c2,     c3, c4
                    now, distance = 4,5,1 => min=1
                3. again
                        0 , 3 , 4 , 7 , 9 , 10
                        c1,     c2, c3,     c4
                    now, distance = 4,3,3 => min=3
                4. now, we have min=1,1,3
                5. max(min) = 3 => answer*/
                    // linear approach (time complexity = O(n*max-min), space complexity = O(1))
                        /*vector <int> arr = {0,3,4,7,9,10};
                        int cows=4;
                        int size=arr.size();
                        div(arr,0,size-1); // sort => time complexity = O(nlogn)
                        aggressive_cows(arr,cows,size); // time complexity = O(n*(max-min))*/
                    // binary approach (time complexity = O(nlog(max-min)), space complexity = O(1))
                        /*vector <int> arr = {0,3,4,7,9,10};
                        int cows=4;
                        int size=arr.size();
                        div(arr,0,size-1); // sort => time complexity = O(nlogn)
                        int minn=arr[0], maxx=arr[0];
                        for(int i=1;i<size;i++){
                            minn=min(minn,arr[i]);
                            maxx=max(maxx,arr[i]);
                        }
                        int minpossibledist=0;
                        int low=1, high=maxx-minn;
                        while(low<=high){ // time complexity = O(log(max-min))
                            int mid=(low+high)/2;
                            int cow=1, prevcow=arr[0];
                            for(int i=1;i<size;i++){ // time complexity = O(n)
                                if(arr[i]-prevcow >= mid){
                                    cow++;
                                    prevcow=arr[i];
                                }
                            }
                            if(cow >= cows) low=mid+1;
                            else high=mid-1;
                        }
                        cout<<"Maximum of minimum distance: "<<high;*/
            // 2. allocation of books
                /*we have given an array of no. of pages that a book has
                like 12,34,67,90 => first book has 12 pages, second has 34, third has 67, and last book has 90 pages
                also we have given the no of students like 2(say)
                now, we have to allocate all the books to the students such that the maximum no. of pages that is allocated
                to a student is minimum
                conditions that has to followed are:
                1. 1 book must be allocated to one student (half pages to one student half to other is not allowed)
                2. each student must get atleast 1 book (no student shoukd be left out)
                3. allocation must be in contiguos order (random book allocation is not permitted)
                for eg, 12,34,67,90 and students=2
                now the possible allocation we can made:
                1. student1 -> 12 and student2 -> 34,67,90 => total -> student1=12 pages, student2=34+67+90=191 pages
                2. student1 -> 12,34 and student2 -> 67,90 -> total -> student1=12+34=46, student2=67+90=157
                3. student1 -> 12,34,67 and student2 -> 90 -> total -> student1=12+34+67=113, student2=90 pages
                now, we have maximum no of pages that we can allot in every possible allocation as; 191,157,113
                so, we have to find the minimum of these pages (min(191,157,113)) => 113
                hence, the ans is 113*/
                    // linear approach (time complexity = O(n^2) approx, space complexity = O(1))
                        // it will take longer time so avoid it in interviews, just directly jump to the binary approach
                    // binary approach (time complexity = O(nlog(aumofelements)), space complexity = O(1))
                        /*int arr[]={12,34,67,90};
                        int students=2;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        // now since the answer will lie between the minimum no of pages to the maximum number of 
                        // pages that can be allocated to any student the loop goes from maximum element 
                        // to the sum of all elements  
                        // and at minimum there can be single student => ans = sum of all books pages (elements)
                        int maxelement=arr[0];
                        int maxx=0;
                        for(int i=0;i<size;i++){ // time complexity = O(n)
                            maxelement=max(maxelement,arr[i]);
                            maxx+=arr[i];
                        }
                        if(students > size) cout<<"Not possible alloaction";
                        else{
                            int low=maxelement, high=maxx;
                            while(low<=high){ // time complexity = O(log(sumofallelements))
                                int student=1; 
                                int sumofpages=0;
                                int mid=(low+high)/2;
                                for(int i=0;i<size;i++){ // time complexity = O(n)
                                    if(sumofpages+arr[i] <= mid) sumofpages+=arr[i];
                                    else{
                                        student++;
                                        sumofpages=arr[i];
                                    }
                                }
                                if(student > students) low=mid+1;
                                else high=mid-1;
                            }
                            cout<<"Minimum of maximum pages: "<<low;
                        }*/
            // 3. painter partition (or, split array largest sum)
                /*it is quite same as the book allocation problem
                1. painter partition:
                    we have given an array of areas which has to be painted and no. of painters
                    each painter has to paint atleast one area
                    time taken to paint the area = area value (10 units of wall takes 10 units of time to paint)
                    area should be divided contiguosly to every painter
                    now answer should contain the minimum of maximum time taken by painters to paint
                        all the area
                    eg, 10,20,30,40 painters=2
                    i) painter1 = 10, painter2 = 20,30,40
                    time -> 10 and 20+30+40=90 => if we allocate 90 units of time so both painters can complete
                    their task within that time => 90 i.e. max(90,10)
                    ii) painter1 = 10,20, painter2 = 30,40
                    time -> 10+20=30 and 30+40=70 => 70 that is max(30,70)
                    iii) painter1 = 10,20,30, painter2 = 40
                    time -> 10+20+30=60 and 40 => 60 that is max(60,40)
                    now, min(90,70,60) = 60 in which both the painters can complete their task
                    => ans = 60
                2. split subarray - largest sum:
                    we have given an array and no of subarrays
                    we have to split the array into those many subarrays such that their maximum sum is minimum
                3. book allocation:
                    we have divided the books pages into the given students such that the maximum number of pages 
                    that each student gets is minimum*/
                    // binary approach (time complexity = O(nlog(sum-maxelement)), space complexity = O(1))
                        /*int arr[]={10,20,30,40};
                        int painters=2;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int maxx=arr[0], sum=0;
                        for(int i=0;i<size;i++){
                            maxx=max(maxx,arr[i]);
                            sum+=arr[i];
                        }
                        int low=maxx, high=sum;
                        while(low<=high){ // time complexity = O(log(sum-max))
                            int painter=1, area=0;
                            int mid=(low+high)/2;
                            for(int i=0;i<size;i++){ // time complexity = O(n)
                                if(area+arr[i] <= mid) area+=arr[i];
                                else{
                                    painter++;
                                    area=arr[i];
                                }
                            }
                            if(painter <= painters) high=mid-1;
                            else low=mid+1;
                        }
                        cout<<"Minimum of maximum time: "<<low;*/
            // 4. minimise maximum distance to gas stations
                /*we have given an array of gas stations in sorted order, elements of which shows the distance or 
                co-ordinate of a gas station and no of gas stations that has to be added
                our task is to return the minimum of maximum distance b/w any two gas stations
                eg, 1,2,3,4,5 no of gas station that has to be added = 4
                1. if we add these gas stations as 1, 2, 3, 4, 5, 6, 7, 8, 9 
                                            dist -   1  1  1  1  1  1  1  1   => max dist = 1
                2. other way 1, 1.25, 1.50, 1.75,   2,   3,  3.5,   4, 5
                    dist -    0.25  0.25  0.25  0.25   1   0.5   0.5  1 => max dist =1
                3. similarly the one more way is 1,  1.5,   2,   2.5,   3,   3.5,   4,   4.5,   5
                                        dist -    0.5    0.5  0.5    0.5  0.5    0.5  0.5    0.5   => max dist = 0.5
                now, the min(1,1,0.5) = 0.5 = answer
                NOTE:- 1) in these types of questions the answer must be return in long double or double datatype
                2) answer within 10^-6 of the actual answer will be accepted => upto 6 decimal places
                3) if we have 1,7 and gas stations = 2
                    one of the way is 1,7,8,9 => min(max(6,1,1)) = min(6) = 6
                    but, we are unable to minimise the distance between already present gas stations (original 
                    that is 1 and 7) => there is no sense to add gas stations at the extremes elements
                    that is in starting or ending because if we place at these extremes the distance between them
                    will always be the same and maximum
                    => the other way 1,2,4,7 => min(max(1,2,3)) = min(3) = 3
                    again there is no sense as if we place just considering one minimum distance (1,2)
                    there will always be something greater (4,7)
                    => so the ideal strategy would be;
                    if we have to place 2 gas stations => 1 g1 g2 7 
                    => dist = g1-1, g2-g1, 7-g2 => 3 sections
                    so, we need to equally divide the distance 6 (7-1) into 3 sections => 2
                    so that there will no chance to get any greater distance
                    1,3,5,7 => 1+2=3, 3+2=5, 5+2=7
                    answer = min(max(2,2,2)) = min(2) = 2*/
                    // brute force sol (time complexity = O((n*gasSationsToAdd)+n), space complexity = O(n))
                        /*int arr[]={1,13,17,23};
                        int gasStations=5;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        // placing the stations
                        int howmanystationsplaced[size-1]={0}; // space complexity = O(n)
                        for(int station=1; station<=gasStations; station++){ // time complexity = O(gasStations)
                            long double maxdist=-1;
                            int maxdistind=-1;
                            for(int i=0;i<size-1;i++){ // time complexity = O(n-1) = O(n) approx(as 1 is constant)
                                long double dist=arr[i+1]-arr[i];
                                long double sectionlen=dist/((long double)howmanystationsplaced[i]+1);
                                if(maxdist < sectionlen){
                                    maxdist=sectionlen;
                                    maxdistind=i;
                                }
                            }
                            howmanystationsplaced[maxdistind]++;
                        }
                        // computing minimum distance
                        long double ans=-1;
                        for(int i=0;i<size-1;i++){ // time complexity = O(n)
                            long double diff=arr[i+1]-arr[i];
                            long double seclen=diff/((long double)howmanystationsplaced[i]+1);
                            ans=max(ans,seclen);
                        }
                        cout<<"Minimum distance of the stations: "<<ans;*/
                    // better sol using priority queue (time complexity = O(nlogn + 2logn*gasStations), space complexity = O(2n))
                        /*int arr[]={1,13,17,23};
                        int gasStations=5;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        int howmanystationsplaced[size-1]={0}; // space complexity = O(n)
                        priority_queue <pair<long double, int>> ans; // space complexity = O(n)
                        for(int i=0;i<size-1;i++) ans.push({arr[i+1]-arr[i], i}); // time complexity = O(n*logn)
                        for(int station=1; station<=gasStations; station++){ // time complexity = O(gasStations)
                            auto maxdist=ans.top(); // time complexity = O(1)
                            ans.pop(); // time complexity = O(logn)
                            int maxdistind=maxdist.second;
                            howmanystationsplaced[maxdistind]++;
                            long double diff = arr[maxdistind+1]-arr[maxdistind];
                            long double newmaxdist = diff/(long double)(howmanystationsplaced[maxdistind]+1);
                            ans.push({newmaxdist, maxdistind}); // time complexity = O(logn)
                        }
                        cout<<"Minimum distance of the stations: "<<ans.top().first;*/
                    // optimal sol using binary approach (time complexity = O(nlog(range)), space complexity = O(1))
                        /*int arr[]={1,13,17,23};
                        int gasstations=5;
                        int size=sizeof(arr)/sizeof(arr[0]);
                        long double low=0, high=0;
                        for(int i=0;i<size-1;i++) high=max(high, (long double)(arr[i+1]-arr[i])); // time complexity = O(n)
                        while(high-low > 1e-6){ // time complexity = O(log(range))
                            long double mid=(low+high)/2.0;
                            int station=0;
                            for (int i=0;i<size-1;i++){ // time complexity = O(n)
                                int howmanystationsplaced=(arr[i+1]-arr[i])/mid;
                                if((arr[i+1]-arr[i]) == howmanystationsplaced*mid) howmanystationsplaced--;
                                station += howmanystationsplaced;
                            }
                            if(station > gasstations) low=mid;
                            else high=mid;
                        }
                        cout<<"Minimum distance of the stations: "<<high;*/
            // 5. median of two sorted arrays
                /*we have two sorted arrays given, our task is to find the median from the merged array of both*/
                    // native/brute force sol (time complexity = O(size1+size2), space complexity = O(size1+size2))
                        /*int arr1[]={1,3,4,7,10,12};
                        int arr2[]={2,3,6,15};
                        int size1=sizeof(arr1)/sizeof(arr1[0]);
                        int size2=sizeof(arr2)/sizeof(arr2[0]);
                        // merging both the arrays
                        int ptr1=0, ptr2=0;
                        int len=size1+size2;
                        int ans[len]; // space complexity = O(size1+size2)
                        int i=0;
                        while(ptr1<size1 && ptr2<size2){ // time complexity = O(min(size1,size2)) = O(size1+size2) in worst case
                            if(arr1[ptr1] <= arr2[ptr2]){
                                ans[i]=arr1[ptr1];
                                ptr1++;
                            }
                            else{
                                ans[i]=arr2[ptr2];
                                ptr2++;
                            }
                            i++;
                        }
                        // following while loops are optional or run only one loop from both of them
                        while(ptr1 < size1){
                            ans[i]=arr1[ptr1];
                            ptr1++;
                            i++;
                        }
                        while(ptr2 < size2){
                            ans[i]=arr2[ptr2];
                            ptr2++;
                            i++;
                        }
                        // finding median
                        if(len%2 == 0){
                            int medianind1=(len/2)-1;
                            int medianind2=len/2;
                            int median=(ans[medianind1]+ans[medianind2])/2;
                            cout<<"Median: "<<median;
                        }
                        else{
                            int medianind=len/2;
                            int median=ans[medianind];
                            cout<<"Median: "<<median;
                        }*/
                    // better sol (time complexity = O(size1+size2), space complexity = O(1))
                        /*int arr1[]={1,3,4,7,10,12};
                        int arr2[]={2,3,6,15};
                        int size1=sizeof(arr1)/sizeof(arr1[0]);
                        int size2=sizeof(arr2)/sizeof(arr2[0]);
                        int len=size1+size2;
                        int ind1=(len/2)-1;
                        int ind2=len/2;
                        int ptr1=0, ptr2=0;
                        int cnt=0;
                        int el1=-1, el2=-1;
                        while(ptr1<size1 && ptr2<size2){ // time complexity = O(min(size1,size2)) = O(size1+size2)
                            int element;
                            if(arr1[ptr1] < arr2[ptr2]){
                                element=arr1[ptr1];
                                ptr1++;
                            }
                            else{
                                element=arr2[ptr2];
                                ptr2++;
                            }
                            if(cnt==ind1) el1=element;
                            if(cnt==ind2) el2=element;
                            cnt++;
                            if(cnt>ind2) break;
                        }
                        // following loops are optional and run only one loop either of them
                        while(ptr1 < size1){
                            int element=arr1[ptr1];
                            ptr1++;
                            if(cnt==ind1) el1=element;
                            if(cnt==ind2) el2=element;
                            cnt++;
                            if(cnt>ind2) break;
                        }
                        while(ptr2 < size2){
                            int element=arr2[ptr2];
                            ptr2++;
                            if(cnt==ind1) el1=element;
                            if(cnt==ind2) el2=element;
                            cnt++;
                            if(cnt>ind2) break;
                        }
                        if(len%2 == 0){
                            double median=(double)(el1+el2)/2.0;
                            cout<<"Median: "<<median;
                        }
                        else{
                            int median=el2;
                            cout<<"Median: "<<median;
                        }*/
                    // optimal sol using binary approach (time complexity = O(log(min(n1,n2))), space complexity = O(1))
                        /*vector <int> arr1={1,3,4,7,10,12};
                        vector <int> arr2={2,3,6,15};
                        int size1=arr1.size();
                        int size2=arr2.size();
                        // finding smaller length array to shorten the binary loop time complexity more
                        if(size1 > size2){
                            swap(arr1,arr2);
                            swap(size1,size2);
                        }
                        // total size of arrays
                        int size=size1+size2;
                        // dividing complete array (arr1+arr2) into two halves
                        int bothhalf=size/2;
                        // low and high points to indices of smaller length array as we have already swapped the array based on size 
                        int low=0, high=size1;
                        while(low<=high){
                            int arr1_el=(low+high)/2;
                            int arr2_el=bothhalf-arr1_el;
                            // if we take 0 element from arr1 (since, arr1[arr1_el-1] will cause boundary crash error in such case)
                            int lefthalf1;
                            if(arr1_el==0) lefthalf1=INT_MIN;
                            else lefthalf1=arr1[arr1_el-1];
                            // if we take 0 element from arr2
                            int lefthalf2;
                            if(arr2_el==0) lefthalf2=INT_MIN;
                            else lefthalf2=arr2[arr2_el-1];
                            // if we take all elements from arr1 (since, arr1[arr1_el] that is arr1[size1] will cause error)
                            int righthalf1;
                            if(arr1_el==size1) righthalf1=INT_MAX;
                            else righthalf1=arr1[arr1_el];
                            // if we take all elements from arr2
                            int righthalf2;
                            if(arr2_el==size2) righthalf2=INT_MAX;
                            else righthalf2=arr2[arr2_el];
                            // for median
                            if(lefthalf1<=righthalf2 && lefthalf2<=righthalf1){
                                double median;
                                // if total size is odd
                                if(size%2 != 0) median=min((double)righthalf1,(double)righthalf2);
                                // if total size is even
                                else median=(max((double)lefthalf1,(double)lefthalf2)+min((double)righthalf1,(double)righthalf2))/2;
                                cout<<"Median: "<<median;
                                break;
                            }
                            // we have taken more elements from arr1 instead of less, so move left
                            else if(lefthalf1 > righthalf2) high=arr1_el-1;
                            // we have taken less elements from arr1 instead of more, so move right
                            else low=arr1_el+1;
                        }*/
            // 6. specific index element from two sorted arrays
                /*we have given two sorted arrays and an element number;
                eg, arr1=2,3,6,7,9 arr2=1,4,8,10 and el_no=4
                now sorted merged array=1,2,3,4,6,7,8,9,10
                now the 4th element is 4 in the merged array
                so ans=4(element)*/
                    // binary approach (time complexity = O(log(min(n1,n2))), space complexity = O(1))
                        /*vector <int> arr1={2,3,6,7,9};
                        vector <int> arr2={1,4,8,10};
                        int elno=4;
                        int size1=arr1.size();
                        int size2=arr2.size();
                        if(size1 > size2){
                            swap(arr1,arr2);
                            swap(size1,size2);
                        }
                        int size=size1+size2;
                        // if k=4 and arr1_el=0(invalid) and size2=3(say), we cannot take more than 3 elements from arr2 
                        // so we need at least some minimum elements from arr1 to make arr1_el=min elements_req(valid)
                        int low=max(0,elno-size2);
                        // if k=4 and size1=3(say) we cannot take 4 elements from arr1 so we need to take other element 
                        // from arr2
                        int high=min(elno,size1); 
                        while(low<=high){
                            int arr1_el=(low+high)/2;
                            int arr2_el=elno-arr1_el;
                            int lefthalf1;
                            if(arr1_el==0) lefthalf1=INT_MIN;
                            else lefthalf1=arr1[arr1_el-1];
                            int lefthalf2;
                            if(arr2_el==0) lefthalf2=INT_MIN;
                            else lefthalf2=arr2[arr2_el-1];
                            int righthalf1;
                            if(arr1_el==size1) righthalf1=INT_MAX;
                            else righthalf1=arr1[arr1_el];
                            int righthalf2;
                            if(arr2_el==size2) righthalf2=INT_MAX;
                            else righthalf2=arr2[arr2_el];
                            if(lefthalf1<=righthalf2 && lefthalf2<=righthalf1){
                                cout<<"Element: "<<max(lefthalf1,lefthalf2);
                                break;
                            }
                            else if(lefthalf1 > righthalf2) high=arr1_el-1;
                            else low=arr1_el+1;
                        }*/
        // on 2D arrays
            // 1. row with max no of 1's
                /*we have given a matrix which only contains 0 and 1
                every row of matrix is sorted
                return the row no containing max no of 1s
                if more than one row contains same answer then return the smaller row no
                for eg;
                row0 -> 0   0   1   1   1 => 3 1s
                row1 -> 0   0   0   0   0 => 0 1s
                row2 -> 0   1   1   1   1 => 4 1s
                row3 -> 0   0   0   0   0 => 0 1s
                row4 -> 0   1   1   1   1 => 4 1s
                so, ans=min(2,4)=2*/
                    // linear approach (time complexity = O(row*col), space complexity = O(1))
                        /*int arr[][5]={{0,0,1,1,1},
                                     {0,0,0,0,0},
                                     {0,1,1,1,1},
                                     {0,0,0,0,0},
                                     {0,1,1,1,1}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int rowno=-1;
                        int maxsum=-1; // since maximum no of 1s row gives max sum than other rows
                        for(int i=0;i<rows;i++){
                            int sum=0;
                            for(int j=0;j<cols;j++) sum+=arr[i][j];
                            if(sum > maxsum){ // if sum >= maxsum then rowno updates if later found the same maxsum
                                maxsum=sum;
                                rowno=i;
                            }
                        }
                        cout<<"Row: "<<rowno;*/
                    // binary approach (time complexity = O(rows*log(cols)), space complexity = O(1))
                        /*int arr[][5]={{0,0,1,1,1},
                                      {0,0,0,0,0},
                                      {0,1,1,1,1},
                                      {0,0,0,0,0},
                                      {0,1,1,1,1}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int min1ind=cols;
                        int rowno=-1;
                        for(int i=0;i<rows;i++){
                            int low=0, high=cols-1;
                            int first1ind=cols;
                            while(low<=high){
                                int mid=(low+high)/2;
                                if(arr[i][mid] == 1){
                                    first1ind=mid;
                                    high=mid-1;
                                }
                                else low=mid+1;
                            }
                            if(first1ind < min1ind){
                                min1ind=first1ind;
                                rowno=i;
                            }
                        }
                        cout<<"Row: "<<rowno;*/
                                    // or
                        /*int arr[][5]={{0,0,1,1,1},
                                      {0,0,0,0,0},
                                      {0,1,1,1,1},
                                      {0,0,0,0,0},
                                      {0,1,1,1,1}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int maxsum=0;
                        int rowno=-1;
                        for(int i=0;i<rows;i++){
                            int *first1inditerator=lower_bound(arr[i],arr[i]+cols,1); // or upper_bound(0)
                            int first1ind=first1inditerator-arr[i];
                            int sum=cols-first1ind;
                            if(sum > maxsum){
                                maxsum=sum;
                                rowno=i;
                            }
                        }
                        cout<<"Row: "<<rowno;*/
            // 2. search target in row-wise sorted matrix (leetcode ques)
                /*we have given a matrix whose each row is sorted and the next row's first element is always 
                greater than the previous row's last element
                we need to give true or false if the given target value exist in the matrix or not
                eg; 1, 3, 5, 7
                    10,11,16,20     => 10,11,16,20 (sorted) and 10 > 7
                    23,30,34,50
                    target=3
                    ans=true*/
                    // brute force sol 1 (time complexity = O((rows*cols) + log(row*cols)), space complexity = O(rows*cols))
                        /*int arr[][4]={{1,3,5,7},
                                      {10,11,16,20},
                                      {23,30,34,50}};
                        int target=3;
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        vector <int> temp; // space complexity = O(rows*cols)
                        for(int i=0;i<rows;i++){ // time complexity = O(rows)
                            for(int j=0;j<cols;j++) temp.push_back(arr[i][j]); // time complexity = O(cols)
                        }
                        bool found=false;
                        int low=0, high=temp.size()-1; 
                        while(low<=high){ // time complexity = O(log(rows*cols))
                            int mid=(low+high)/2;
                            if(temp[mid] == target){
                                found=true;
                                cout<<true;
                                break;
                            }
                            else if(temp[mid] < target) low=mid+1;
                            else high=mid-1;
                        }
                        if(!found) cout<<false;*/
                    // linear/brute force sol 2 (time complexity = O(rows*cols), space complexity = O(1))
                        /*int arr[][4]={{1,3,5,7},
                                      {10,11,16,20},
                                      {23,30,34,50}};
                        int target=3;
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        bool found=false;
                        for(int i=0;i<rows;i++){ // time complexity = O(rows)
                            for(int j=0;j<cols;j++){ // time complexity = O(cols)
                                if(arr[i][j] == target){
                                    found=true;
                                    break;
                                }
                            }
                            if(found){
                                cout<<true;
                                break;
                            }
                        }
                        if(!found) cout<<false;*/
                    // better approach 1 (time complexity = O(rows*log(cols)), space complexity = O(1))
                        /*int arr[][4]={{1,3,5,7},
                                      {10,11,16,20},
                                      {23,30,34,50}};
                        int target=3;
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        bool found=false;
                        for(int i=0;i<rows;i++){ // time complexity = O(rows)
                            int low=0, high=cols-1;
                            while(low<=high){ // time complexity = O(log(cols))
                                int mid=(low+high)/2;
                                if(arr[i][mid] == target){
                                    found=true;
                                    break;
                                }
                                else if(arr[i][mid] < target) low=mid+1;
                                else high=mid-1;
                            }
                            if(found){
                                cout<<true;
                                break;
                            }
                        }
                        if(!found) cout<<false;*/
                    // better approach 2 (time complexity = O(rows+cols), space complexity = O(1))
                        /*int arr[][4]={{1,3,5,7},
                                      {10,11,16,20},
                                      {23,30,34,50}};
                        int target=3;
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        bool found=false;
                        int r=0, c=cols-1;
                        while(r<rows && c>=0){ // time complexity = O(rows+cols)
                            if(arr[r][c] == target){
                                found=true;
                                cout<<true;
                                break;
                            }
                            else if(arr[r][c] < target) r++;
                            else c--;
                        }
                        if(!found) cout<<false;*/
                    // optimal approach 1 (time complexity = O(log(rows*cols)), space complexity = O(1))
                        /*int arr[][4]={{1,3,5,7},
                                      {10,11,16,20},
                                      {23,30,34,50}};
                        int target=3;
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        bool found=false;
                        int low=0, high=(rows*cols)-1; // imaginary indices for a splitted 1D array
                        while(low<=high){ // time complexity = O(log(rows*cols))
                            int mid=(low+high)/2;
                            int actualrow=mid/cols;
                            int actualcol=mid%cols;
                            if(arr[actualrow][actualcol] == target){
                                found=true;
                                cout<<true;
                                break;
                            }
                            else if(arr[actualrow][actualcol] < target) low=mid+1;
                            else high=mid-1;
                        }
                        if(!found) cout<<false;*/
                    // optimal(binary) approach 2 (time complexity = O(log(rows)+log(cols)), space complexity = O(1))
                        /*int arr[][4]={{1,3,5,7},
                                      {10,11,16,20},
                                      {23,30,34,50}};
                        int target=3;
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int low1=0, high1=rows-1;
                        bool found=false;
                        while(low1<=high1){ // time complexity = O(log(rows))
                            int mid1=(low1+high1)/2;
                            if(arr[mid1][0] == target){
                                found=true;
                                break;
                            }
                            else if(arr[mid1][0]<target && arr[mid1][cols-1]>=target){
                                int low2=0, high2=cols-1;
                                while(low2<=high2){ // time complexity = O(log(cols))
                                    int mid2=(low2+high2)/2;
                                    if(arr[mid1][mid2] == target){
                                        found=true;
                                        break;
                                    }
                                    else if(arr[mid1][mid2] < target) low2=mid2+1;
                                    else high2=mid2-1;
                                }
                                break;
                            }
                            else if(arr[mid1][0] < target) low1=mid1+1;
                            else high1=mid1-1;
                        }
                        cout<<found;*/
            // 3. search target in row-wise as well as column-wise sorted matrix (gfg ques)
                /*we have given a matrix whose each row is sorted from left to right and
                each column is also sorted from top to bottom
                we need to find the target value given 
                if present; print index where present
                else; print element not found
                eg; 10,20,30,40
                    15,25,35,45
                    27,29,37,48
                    32,33,39,50
                target=29 ans=found at(2,1)
                target=100 ans=element not found*/
                    // binary approach (time complexity = O(rows+cols), space complexity = O(1))
                        /*int arr[][4]={{10,20,30,40},
                                      {15,25,35,45},
                                      {27,29,37,48},
                                      {32,33,39,50}};
                        int target=29;
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int r=0, c=cols-1;
                        bool found=false;
                        while(r<rows && c>=0){ // time complexity = O(rows+cols)
                            if(arr[r][c] == target){
                                found=true;
                                cout<<"Found at ("<<r<<","<<c<<")";
                                break;
                            }
                            else if(arr[r][c] < target) r++;
                            else c--;
                        }
                        if(found==false) cout<<"Element not found";*/
            // 4. peak element
                /*a 2D array is given whose two adjacent cells cannot be same, we need to find peak element
                eg; 4,2,5,1,4,5
                    2,9,3,2,3,2
                    1,7,6,0,1,3
                    3,6,2,3,7,2
                here, clearly mentioned that if we see arr[1][1] that is 9
                so, arr[0][0] (=2), arr[1][0] (=2), arr[1][2] =(3), and arr[2][1] (=7) can never be equal to 9 
                since these are adjacent cells of arr[1][1]
                in the above matrix the peak element is 9 coz it is > left, right, top, and bottom elements
                hence ans=(1,1)
                but if we see arr[0][2] = 5 it is also a peak element since it is > left, right, bottom, and top(-1)
                elements
                => there is one extra boundary of -1 surrounded/covering the matrix
                we need to just print the index (row,col) of any one peak element*/
                    // brute force sol 1 (time complexity = O(4*rows*cols) for worst case, space complexity = O(1))
                        /*int arr[][6]={{4,2,5,1,4,5},
                                      {2,9,3,2,3,2},
                                      {1,7,6,0,1,3},
                                      {3,6,2,3,7,2}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int top=0, left=0, right=0, bottom=0;
                        bool found=false;
                        for(int i=0;i<rows;i++){ // time complexity = O(rows)
                            for(int j=0;j<cols;j++){ // time complexity = O(cols)
                                if(i==0) top=-1;
                                else top=arr[i-1][j];
                                if(i == rows-1) bottom=-1;
                                else bottom=arr[i+1][j];
                                if(j==0) left=-1;
                                else left=arr[i][j-1];
                                if(j == cols-1) right=-1;
                                else right=arr[i][j+1];
                                if(arr[i][j]>top && arr[i][j]>left && arr[i][j]>right && arr[i][j]>bottom){
                                    found=true;
                                    cout<<"Peak element is at ("<<i<<","<<j<<")";
                                    break;
                                }
                            }
                            if(found) break;
                        }
                        if(!found) cout<<"No peak element";*/
                    // brute force sol 2 using largest element (time complexity = O(rows*cols), space complexity = O(1))
                        /*int arr[][6]={{4,2,5,1,4,5},
                                      {2,9,3,2,3,2},
                                      {1,7,6,0,1,3},
                                      {3,6,2,3,7,2}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int peak=-1;
                        int r=-1, c=-1;
                        for(int i=0;i<rows;i++){ // time complexity = O(rows)
                            for(int j=0;j<cols;j++){ // time complexity = O(cols)
                                if(peak < arr[i][j]){
                                    peak=arr[i][j];
                                    r=i;
                                    c=j;
                                }
                            }
                        }
                        if(peak==-1) cout<<"No peak element";
                        else cout<<"Peak element is at ("<<r<<","<<c<<")";*/
                    // optimal sol using binary approach (time complexity = O(rows*log(cols)), space complexity = O(1))
                        /*int arr[][6]={{4,2,5,1,4,5},
                                      {2,9,3,2,3,2},
                                      {1,7,6,0,1,3},
                                      {3,6,2,3,7,2}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int low=0, high=cols-1;
                        bool found=false;
                        while(low<=high){ // time complexity = O(log(cols))
                            int mid=(low+high)/2;
                            int maxx=-1;
                            int r=-1;
                            for(int i=0;i<rows;i++){ // time complexity = O(rows)
                                if(maxx < arr[i][mid]){
                                    maxx=arr[i][mid];
                                    r=i;
                                }
                            }
                            int left = (mid==0) ? -1 : arr[r][mid-1];
                            int right = (mid==cols-1) ? -1 : arr[r][mid+1];
                            if(maxx>left && maxx>right){
                                found=true;
                                cout<<"Peak element is at ("<<r<<","<<mid<<")";
                                break;
                            }
                            else if(maxx < left) high=mid-1;
                            else low=mid+1;
                        }
                        if(!found) cout<<"No peak element";*/
            // 5. median of a row-wise sorted matrix
                /*we are given a matrix having odd no of rows and odd no of columns, and also it is row-wise sorted
                from left to right
                our task is to find the median of the matrix
                eg; 1, 5, 7, 9,11
                    2, 3, 4, 5,10
                    9,10,12,14,16
                now if we write it as a 1D array in sorted order, it would be: 
                1,2,3,4,5,5,7,9,9,10,10,11,12,14,16 => median=9
                hence ans=9
                it is also given that the ans can be as small as 1 and as large as 10^9*/
                    // brute force sol (time complexity = O(rows*cols)+O((rows*cols)*log(rows*cols)), space complexity = O(rows*cols))
                        /*int arr[][5]={{1, 5, 7, 9,11},
                                      {2, 3, 4, 5,10},
                                      {9,10,12,14,16}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        vector <int> temp; // space complexity = O(rows*cols)
                        for(int i=0;i<rows;i++){ // time complexity = O(rows)
                            for(int j=0;j<cols;j++) temp.push_back(arr[i][j]); // time complexity = O(cols)
                        }
                        sort(temp.begin(),temp.end()); // time complexity = O((rows*cols)*log(rows*cols))
                        int size=temp.size();
                        int medianind=size/2;
                        cout<<"Median: "<<temp[medianind];*/
                    // optimal (binary) sol (time complexity = O(log(10^9)*rows*log(cols)), space complexity = O(1))
                        /*int arr[][5]={{1, 5, 7, 9,11},
                                      {2, 3, 4, 5,10},
                                      {9,10,12,14,16}};
                        int rows=sizeof(arr)/sizeof(arr[0]);
                        int cols=sizeof(arr[0])/sizeof(arr[0][0]);
                        int size=rows*cols;
                        int medianlies=size/2;
                        int low=INT_MIN, high=INT_MAX;
                        for(int i=0;i<rows;i++){ // time complexity = O(rows)
                            low=min(low,arr[i][0]);
                            high=max(high,arr[i][cols-1]);
                        }
                        // for median we are sure it has 7 elements on both the sides left and right
                        // and since median is identifiable in sorted array => left side of it is always <= median
                        // ('=' in case of duplicates) and right side >= median ('=' in case of duplicates)
                        // so, we are definitely sure that the total number of elements <= median should always be > 7
                        // so for binary search the element we pick (mid), we need to check how many elements are <= that element (mid)
                        // that should be > 7 (size/2)
                        // the number (mid) having first occurence of condition met is our median
                        // eg; searchspace     = 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 => mid
                        //     no of elements <= 1,2,3,4,6,6,7,7,9,11,12,13,13,14,14,15
                        //     the first occurence having (no of elements <= mid) > 7 is 9
                        //     => answer is the mid having 9 no of elements that is 9
                        while(low<=high){ // time complexity = O(log(10^9))
                            int mid=(low+high)/2;
                            int elementslesserequals=0;
                            for(int i=0;i<rows;i++) elementslesserequals+=upper_bound(arr[i],arr[i]+cols,mid)-arr[i]; // time complexity = O(rows*log(cols))
                            if(elementslesserequals <= medianlies) low=mid+1;
                            else high=mid-1;
                        }
                        cout<<"Median: "<<low;*/

// strings

// linked list
    // single linked list
        /*what is it?
            1. it does not store elements in contiguos heap memory area
            2. size of linked list can be grown or reduced at any moment
            3. a kind of data structure that stores an element at any random memory location and the address of its 
            next element
            4. first element is called head and the last is called tail, others are nodes
            5. last element stores its value and the next address as null since no more element will be there
            6. in c++ it is nullptr and in java it is null
        where is used?
            1. stack data structure
            2. queue data structure
            3. browsers in real life
        how to create?
            1. using self/user defined datatype - struct, class
            2. just like if we have to store the address of an element we define int* ptr
            3. similarly we have to define int* next in linked list
            4. but, we have to store data as well as next pointer together as a single unit
            5. there is no built in datatype that allows it
            6. so we create our own datatype that can be named anything by using struct keyword
            7. eg; struct node{ // node is the name of datatype
                        int data;
                        node* next; // just like int* ptr
                        // in order to define the values of these variables we need to use constructors
                        node(data1, next1){ // constructor have same method/datatype name => here it is parameterised constructor
                            data=data1;
                            next=next1;
                        }
                    }
        how  to initialise values
            1. by using in similar way like built in datatypes:
                node x = node(2,nullptr); // like int x=2
                the only thing is we can assign the values by using constructors and the next is null for now
                also if we want a pointer to the variable x we can define it like node* ptr = &x; like int* ptr=&x;
                but remember if we initialise by this method, it is just a variable not a memory location
            2. the simplest way is:
                node* y = new node(2,nullptr);
                it automatically creates the memory location and points to that memory
                unlike in first approach where we were first assign the variable value then a pointer that points to
                that memory location where the value stored
        memory space used?
            1. we are storing only data and a next pointer
            2. but is completely depends on the user what they are storing
            3. also on systems like:
                on 32-bit system - int takes 4 bytes and pointer takes 4 bytes = total 8 bytes
                on 64-bit system - int takes 4 bytes and pointer takes 8 bytes = total 12 bytes
        NOTE: it is named as singly linked list because of its directional flow, it moves only in forward direction
        that is we can traverse only in single direction but not in backward direction as we are not storing any
        pointer inside the datatype which stores the previous value, we are just keeping the current data and next 
        data pointer*/
            // struct
                /*we don't have oops concepts that can be applied using struct*/
                    // way 1 to initialise
                        /*Node ptr = Node(2,nullptr); 
                        // cout<<ptr; => throws error since it behaves as object so need '.' operator to either access data or next pointer because it is an object, that is given below line
                        cout<<ptr.data<<endl;
                        cout<<ptr.next;*/
                    // way 2 to initialise
                        /*vector <int> elements = {2,5,8,7};
                        Node* ptr = new Node(elements[0], nullptr); 
                        cout<<ptr<<endl; // return reference of element 2 in memory
                        cout<<ptr->data<<endl; // dereferencing data
                        cout<<ptr->next; // dereferencing next pointer*/
            // class
                /*1. we have the oops concepts in it like abstraction, encapsulation, inheritance, polymorphism, etc
                2. it works similarly like struct hence no need to change in the code except instead of struct we use 
                keyword class and that's it!*/
                    /*node* ptr = new node(2);
                    cout<<ptr->data<<endl;
                    cout<<ptr->next;*/
            // basic operations
                // convert array into linked list (time complexity = O(n))
                    /*vector <int> arr={12,5,8,7};
                    int size=arr.size();
                    head* ptr=arrtolinkedlist(arr,size);
                    cout<<ptr->data<<endl;
                    cout<<ptr->next;*/
                // traversal (time complexity = O(n))
                    /*vector <int> arr = {12,5,8,7};
                    int size=arr.size();
                    head* headptr=arrtolinkedlist(arr,size);
                    head* tempheadptr = headptr;
                    while(tempheadptr){ // == while(tempheadptr != null)
                        cout<<tempheadptr->data<<" ";
                        tempheadptr =  tempheadptr->next;
                    }
                    cout<<endl; 
                    print(headptr); // or can use a function prefereably*/
                // length (time complexity = O(n))
                    /*vector <int> arr = {12,5,8,7};
                    int size=arr.size();
                    head* headptr=arrtolinkedlist(arr,size);
                    head* tempheadptr=headptr;
                    int length=0;
                    while(tempheadptr){
                        tempheadptr=tempheadptr->next;
                        length++;
                    }
                    cout<<"Length of linked list: "<<length;
                    cout<<endl;
                    int l=lengthoflinkedlist(headptr);
                    cout<<"Length of linked list: "<<l; // using function*/
                // search an element (time complexity = O(n))
                    /*vector <int> arr = {12,5,8,7};
                    int target=5;
                    int size=arr.size();
                    head* headptr=arrtolinkedlist(arr, size);
                    head* tempheadptr=headptr;
                    bool found=false;
                    while(tempheadptr){
                        if(tempheadptr->data == target){
                            found=true;
                            cout<<true;
                            break;
                        }
                        tempheadptr=tempheadptr->next;
                    }
                    if(!found) cout<<false;
                    cout<<endl;
                    bool ans=search(headptr, target); // using function
                    cout<<ans;*/
                // deletion
                    /*vector <int> arr = {12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                    int size=arr.size();
                    head* headptr=arrtolinkedlist(arr,size);*/
                        // 1. head (time complexity = O(1))
                            /*head* newheadptr=deletehead(headptr);
                            print(newheadptr);*/
                        // 2. tail (time complexity = O(n))
                            /*headptr=deletetail(headptr);
                            print(headptr);*/
                        // 3. specific position (k-th element) (time complexity = O(position))
                            /*int position=5;
                            headptr=deleteposition(headptr, position);
                            print(headptr);*/
                        // 4. specific value (time complexity = O(n))
                            /*int element=6;
                            headptr=deleteelement(headptr, element);
                            print(headptr);*/
                // insertion
                    /*vector <int> arr = {12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                    int size=arr.size();
                    head* headptr=arrtolinkedlist(arr,size);*/
                        // 1. head (time complexity = O(1))
                            /*head* newheadptr=inserthead(headptr, 1);
                            print(newheadptr);*/
                        // 2. tail (time complexity = O(n))
                            /*headptr=inserttail(headptr, 3);
                            print(headptr);*/
                        // 3. specific position (time complexity = O(position))
                            /*headptr=insertatposition(headptr, 4, 1);
                            print(headptr);*/
                        // 4. specific value position (time complexity = O(element position))
                            /*headptr=insertatotherelementplace(headptr, 6, 0);
                        print(headptr);*/
            // medium questions
                // 1. middle node of list
                    // brute force sol (time complexity = O(n+n/2), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr, arr.size());
                        head* midnode=middlenode1(headptr);
                        cout<<"Middle node: "<<midnode->data;*/
                    // optimal sol (time complexity = O(n/2), space complexity = O(1))
                        // tortoise and hare algorithm
                            /*in this the intuition we have like if person1 has speed s and the the person2 has 
                            speed s/2 => if person1 covers distance d in a particular time period
                            then the person2 covers the distance d/2 in the same time period
                            => mid distance
                            similarly we have two pointers here; slow and fast, they both move at same time (simultaneously)
                            but when slow moves 1 step, the fast should move 2 steps
                            hence at the end of list, the slow pointer should be at the mid node as the fast has already covered
                            the entire nodes/list 
                            NOTE:- in odd length case they start from odd element that is 1st element => fast stops at last element
                            as the last element is of odd element, but in case of even length they again start from an odd element
                            that is 1st and fast will stop at NULL as the last element which is odd will definately be NULL*/
                                /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                                head* headptr=arrtolinkedlist(arr, arr.size());
                                head* midnode=middlenode2(headptr);
                                cout<<"Middle node: "<<midnode->data;*/
                // 2. reverse the list
                    // brute force sol/iterative approach (time complexity = O(2n), space complexity = O(n))
                        /*vector <int> arr={12,5,8,7};
                        head* headptr=arrtolinkedlist(arr, arr.size());
                        headptr=reverselist1(headptr);
                        print(headptr);*/
                    // better sol by swapping links (time complexity = O(n), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7};
                        head* headptr=arrtolinkedlist(arr, arr.size());
                        head* newheadptr=reverselist2(headptr);
                        print(newheadptr);*/
                    // recursive approach (time complexity = O(n), space complexity = O(n))
                        /*vector <int> arr={12,5,8,7};
                        head* headptr=arrtolinkedlist(arr, arr.size());
                        head* newheadptr=reverselist3(headptr);
                        print(newheadptr);*/
                // 3. detect a loop
                    // brute force sol using hashing (time complexity = O(n*2logn), space complexity = O(n))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptrnoloop=arrtolinkedlist(arr, arr.size());
                        head* headptrloop=arrtolooplinkedlist(arr);
                        cout<<"Array having loop: "<<checkloop1(headptrnoloop);
                        cout<<endl;
                        cout<<"Array having loop: "<<checkloop1(headptrloop);*/
                    // optimal sol (time complexity = O(n), space complexity = O(1))
                        // Floyd’s Cycle Detection Algorithm/ tortoise hare algorithm
                            /*where slow and fast pointer is at same node => there must be a loop in linked list
                            otherwise it is a linear linked list*/
                                /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                                head* headptrloop=arrtolooplinkedlist(arr);
                                head* headptrnoloop=arrtolinkedlist(arr, arr.size());
                                cout<<"Array having loop: "<<checkloop2(headptrloop);
                                cout<<endl;
                                cout<<"Array having loop: "<<checkloop2(headptrnoloop);*/
                // 4. starting node of loop in a list
                    // brute force sol using hashing (time complexity = O(n*2logn), space complexity = O(n))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptrloop=arrtolooplinkedlist(arr);
                        head* loopstartnode=loopnode1(headptrloop);
                        cout<<"Loop node: "<<loopstartnode->data;*/
                    // optimal sol using tortoise and hare algo (time complexity = O(n+firstloopnodeposition), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptrloop=arrtolooplinkedlist(arr);
                        head* loopstartnode=loopnode2(headptrloop);
                        cout<<"Loop node: "<<loopstartnode;*/
                // 5. length of loop
                    // brute force sol (time complexity = O(n*2logn + lengthofloop), space complexity = O(n))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptrloop=arrtolooplinkedlist(arr);
                        int length1=lengthofloop1(headptrloop);
                        cout<<"Length of loop: "<<length1<<endl;
                        head* headptrnoloop=arrtolinkedlist(arr,arr.size());
                        int length2=lengthofloop1 (headptrnoloop);
                        cout<<"Length of loop: "<<length2;*/
                    // better sol (time complexity = O(2*logn), space complexity = O(n))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptrloop=arrtolooplinkedlist(arr);
                        int length1=lengthofloop2(headptrloop);
                        cout<<"Length of loop: "<<length1<<endl;
                        head* headptrnoloop=arrtolinkedlist(arr,arr.size());
                        int length2=lengthofloop2(headptrnoloop);
                        cout<<"Length of loop: "<<length2;*/
                    // optimal sol (time complexity = O(n + loopnode + lengthofloop), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptrloop=arrtolooplinkedlist(arr);
                        int length1=lengthofloop3(headptrloop);
                        cout<<"Length of loop: "<<length1<<endl;
                        head* headptrnoloop=arrtolinkedlist(arr,arr.size());
                        int length2=lengthofloop3(headptrnoloop);
                        cout<<"Length of loop: "<<length2;*/
                // 6. palindrome list
                    // brute force sol (time complexity = O(2n), space complexity = O(n))
                        /*vector <int> arr1={1,2,3,2,1};
                        head* headptr1=arrtolinkedlist(arr1,arr1.size());
                        cout<<"Palindrome list: "<<palindromelist1(headptr1);
                        cout<<endl;
                        vector <int> arr2={1,2,3,3,2};
                        head* headptr2=arrtolinkedlist(arr2,arr2.size());
                        cout<<"Palindrome list: "<<palindromelist1(headptr2);*/
                    // optimal sol (time complexity = O(4*(n/2)=2n), space complexity = O(1))
                        /*vector <int> arr1={1,2,3,2,1};
                        head* headptr1=arrtolinkedlist(arr1,arr1.size());
                        cout<<"Palindrome list: "<<palindromelist2(headptr1);
                        cout<<endl;
                        vector <int> arr2={1,2,3,3,2};
                        head* headptr2=arrtolinkedlist(arr2,arr2.size());
                        cout<<"Palindrome list: "<<palindromelist2(headptr2);*/
                // 7. grouping odd and even position nodes inside the list
                    // brute force sol (time complexity = O(n+n/2+n/2)=O(2n), space complexity = O(n))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        headptr=groupoddeven1(headptr);
                        print(headptr);*/
                    // optimal sol (time complexity = O(n), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        headptr=groupoddeven2(headptr);
                        print(headptr);*/
                // 8. remove a node from last of the list
                    // brute force sol (time complexity = O(2n), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        headptr=removenodelast1(headptr,1);
                        print(headptr);*/
                    // optimal sol (time complexity = O(n), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        headptr=removenodelast2(headptr,3);
                        print(headptr);*/
                // 9. remove middle node from the list
                    // brute force sol (time complexity = O(n+n/2), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        headptr=removemidnode1(headptr);
                        print(headptr);*/
                    // optimal sol 1 (time complexity = O(n), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        headptr=removemidnode2(headptr);
                        print(headptr);*/
                    // optimal sol 2 (time complexity = O(n/2), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        headptr=removemidnode3(headptr);
                        print(headptr);*/
                // 10. merge two sorted lists
                    // brute force sol (time complexity = O(2*(n1+n2)+((n1+n2)*log(n1+n2))), space complexity = O(2*(n1+n2)))
                        /*vector <int> arr1={5,6,7,8,9,11,12,13};
                        head* headptr1=arrtolinkedlist(arr1,arr1.size());
                        vector <int> arr2={2,4,10,14,16,17,18,20};
                        head* headptr2=arrtolinkedlist(arr2,arr2.size());
                        head* newhead=mergetwosortedlists1(headptr1, headptr2);
                        print(newhead);*/
                    // optimal sol (time complexity = O(n1+n2), space complexity = O(1))
                        /*vector <int> arr1={5,6,7,8,9,11,12,13};
                        head* headptr1=arrtolinkedlist(arr1,arr1.size());
                        vector <int> arr2={2,4,10,14,16,17,18,20};
                        head* headptr2=arrtolinkedlist(arr2,arr2.size());
                        head* newhead=mergetwosortedlists2(headptr1, headptr2);
                        print(newhead);*/
                // 11. sort the list
                    // brute force sol (time complexity = O(n+nlogn+n)=O(2n+nlogn), space compplexity = O(n))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        head* newheadptr=sortlist1(headptr);
                        print(newheadptr);*/
                    // optimal sol using merge sort algorithm (time complexity = O(logn*(n+n/2)), space complexity = O(logn) just for internal recursive stack space)
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        head* newheadptr=sortlist2divide(headptr);
                        print(newheadptr);*/
                // 12. sort list containing 0s, 1s, and 2s
                    // brute force sol (time complexity = O(2n), space complexity = O(1))
                        /*vector <int> arr={0,1,2,0,0,0,2,1,2,1,2,2,2,1,1,1,1,0,1,2};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        head* newheadptr=sortlistof012_1(headptr);
                        print(newheadptr);*/
                    // optimal sol (time complexity = O(n), space complexity = O(1))
                        /*vector <int> arr={0,1,2,0,0,0,2,1,2,1,2,2,2,1,1,1,1,0,1,2};
                        head* headptr=arrtolinkedlist(arr,arr.size());
                        head* newheadptr=sortlistof012_2(headptr);
                        print(newheadptr);*/
                // 13. find intersection point of Y list
                    /*we have given two linked list in a way given below:
                            1->2->3->4->5----
                                             \-->15->25->35->NULL
                                             /
                            10->20->30->40---
                        in the lists above we can see a Y-like pattern where 5->next is actually the 40->next
                        now we need to find the intersection point which is 5->next or 40->next where both the 
                        linked lists meet or can say that the first common node of both the lists
                        so ans = 15(not only the value 15 but the whole node)*/
                        // brute force sol (time complexity = O(n1*n2), space complexity = O(1))
                            /*vector <int> arr1={3,1};
                            head* headptr1=arrtolinkedlist(arr1,arr1.size());
                            vector <int> arr2={1,2,4,5};
                            head* headptr2=arrtolinkedlist(arr2,arr2.size());
                            vector <int> common={4,6,2};
                            head* headptrcommon=arrtolinkedlist(common,common.size());
                            createYlist(headptr1, headptr2, headptrcommon);
                            head* commonnode=intersectionnodeofYlist1(headptr1, headptr2);
                            cout<<"Intersection node: "<<commonnode->data;*/
                        // better sol 1 using hashing (time complexity = O(n1logn1+n2logn1), space complexity = O(n1))
                            /*vector <int> arr1={3,1};
                            head* headptr1=arrtolinkedlist(arr1,arr1.size());
                            vector <int> arr2={1,2,4,5};
                            head* headptr2=arrtolinkedlist(arr2,arr2.size());
                            vector <int> common={4,6,2};
                            head* headptrcommon=arrtolinkedlist(common,common.size());
                            createYlist(headptr1, headptr2, headptrcommon);
                            head* commonnode=intersectionnodeofYlist2(headptr1, headptr2);
                            cout<<"Intersection node: "<<commonnode->data;*/
                        // better sol 2 using length difference (time complexity = O(n1+n2+|n1-n2|+min(n1,n2))=O(n1+n2+max(n1,n2)), space complexity = O(1))
                            /*vector <int> arr1={3,1};
                            head* headptr1=arrtolinkedlist(arr1,arr1.size());
                            vector <int> arr2={1,2,4,5};
                            head* headptr2=arrtolinkedlist(arr2,arr2.size());
                            vector <int> common={4,6,2};
                            head* headptrcommon=arrtolinkedlist(common,common.size());
                            createYlist(headptr1, headptr2, headptrcommon);
                            head* commonnode=intersectionnodeofYlist3(headptr1, headptr2);
                            cout<<"Intersection node: "<<commonnode->data;*/
                        // optimal sol (time complexity = O(n1+n2), space complexity = O(1))
                            /*vector <int> arr1={3,1};
                            head* headptr1=arrtolinkedlist(arr1,arr1.size());
                            vector <int> arr2={1,2,4,5};
                            head* headptr2=arrtolinkedlist(arr2,arr2.size());
                            vector <int> common={4,6,2};
                            head* headptrcommon=arrtolinkedlist(common,common.size());
                            createYlist(headptr1, headptr2, headptrcommon);
                            head* commonnode=intersectionnodeofYlist4(headptr1, headptr2);
                            cout<<"Intersection node: "<<commonnode->data;*/
                // 14. add 1 to data represented by list
                    /*we have given a list containing data values like;
                    1->5->9->NULL now it represents a total of 159
                    now if we add 1 to the value we get that is 159 it becomes 160
                    our task is to return this 160 in terms of the list like
                    1->6->0
                    NOTE:- if in case the list is like; 9->9->9-NULL => 999+1=1000
                    in that case we have to add a new node in starting and that will be the head of the ans list
                    => 1->0->0->0*/
                        // brute force sol (time complexity = O(3n), space complexity = O(1))
                            /*vector <int> arr1={1,5,9};
                            head* headptr1=arrtolinkedlist(arr1,arr1.size());
                            head* newhead1=add1tolistconcatdata_1(headptr1);
                            print(newhead1);
                            cout<<endl;
                            vector <int> arr2={9,9,9};
                            head* headptr2=arrtolinkedlist(arr2,arr2.size());
                            head* newhead2=add1tolistconcatdata_1(headptr2);
                            print(newhead2);*/
                        // optimal sol using recursion (time complexity = O(), space complexity = O())
                            vector <int> arr1={1,5,9};
                            head* headptr1=arrtolinkedlist(arr1,arr1.size());
                            head* newhead1=add1tolistconcatdata_2(headptr1);
                            print(newhead1);
                            cout<<endl;
                            vector <int> arr2={9,9,9};
                            head* headptr2=arrtolinkedlist(arr2,arr2.size());
                            head* newhead2=add1tolistconcatdata_2(headptr2);
                            print(newhead2);
    
    // double linked list
        /*what is it?
            it is named as doubly linked list because of its directional flow, it moves in both the directions 
            forward as well as in backward direction, that is we can traverse in double direction as we are storing the
            current data, pointer which points the previous value, and pointer which points the next value
            inside the datatype
        representation in c++/java?
            struct node{ // node is the name of datatype
                int data;
                node* next; // just like int* ptr
                node* prev;
                // in order to define the values of these variables we need to use constructors
                node(data1, next1, prev1){ // constructor have same method/datatype name => here it is parameterised constructor
                    data=data1;
                    next=next1;
                    prev=prev1;
                }
            }*/
            // struct
                // way 1
                    /*nodedll ptr=nodedll(5,nullptr,nullptr);
                    cout<<ptr.data<<endl;
                    cout<<ptr.prev<<endl;
                    cout<<ptr.next;*/
                // way 2
                    /*nodedll* ptr=new nodedll(5,nullptr,nullptr);
                    cout<<ptr->data<<endl;
                    cout<<ptr->prev<<endl;
                    cout<<ptr->next;*/
            // class
                /*Nodedll* ptr=new Nodedll(4,NULL,NULL);
                cout<<ptr->data<<endl;
                cout<<ptr->prev<<endl;
                cout<<ptr->next;*/
            // convert array into double linked list
                /*vector <int> arr={12,5,8,7};
                headdll* head=arrtodll(arr);
                cout<<head->data;*/
            // traversal
                /*vector <int> arr={12,5,8,7};
                headdll* head=arrtodll(arr);
                printdll(head);*/
            // length same as single linked list
                /*vector <int> arr={12,5,8,7};
                headdll* headptr=arrtodll(arr);
                int length=lengthofdll(headptr);
                cout<<"Length: "<<length;*/
            // search an element same as single linked list
            // deletion
                /*vector <int> arr = {12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                headdll* headptr=arrtodll(arr);*/
                    // 1. head (time complexity = O(1))
                        /*headdll* newhead=deleteheaddll(headptr);
                        printdll(newhead);*/
                    // 2. tail (time complexity = O(n))
                        /*headptr=deletetaildll(headptr);
                        printdll(headptr);*/
                    // 3. position (time complexity = O(position))
                        /*headptr=deletepositiondll(headptr,0);
                        printdll(headptr);*/
                    // 4. value (time complexity = O(element position))
                        /*headptr=deleteelementdll(headptr,13);
                        printdll(headptr);*/
            // insertion
                /*vector <int> arr = {12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                headdll* headptr=arrtodll(arr);*/
                    // 1. head (time complexity = O(1))
                        /*headdll* newheadptr=insertheaddll(headptr, 3);
                        printdll(newheadptr);*/
                    // 2. tail (time complexity = O(n))
                        /*headptr=inserttaildll(headptr, 3);
                        printdll(headptr);*/
                    // 3. position (time complexity = O(position))
                        /*headptr=insertpositiondll(headptr, 5, 0);
                        printdll(headptr);*/
                    // 4. value (time complexity = O(element position))
                        /*headptr=insertatotherelementplacedll(headptr,11,0);
                        printdll(headptr);*/
                // reverse the doubly linked list
                    // brute force sol using stack (time complexity = O(2n), space complexity = O(n)) => by value not the nodes
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        headdll* headptr=arrtodll(arr);
                        headptr=reversedll1(headptr);
                        printdll(headptr);*/
                    // optimal sol using links swapping (time complexity = O(n), space complexity = O(1))
                        /*vector <int> arr={12,5,8,7,9,6,13,11,17,16,20,18,14,10,2,4};
                        headdll* headptr=arrtodll(arr);
                        headdll* newhead=reversedll2(headptr);
                        printdll(newhead);*/

    return 0;
}