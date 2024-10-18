// Description
// Find the number of binary strings of length n where “0100” is not present as a substring.

// Input Format
// The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

// The first and only line of each test case contains an integer n.

// Output Format
// For each test case, print the number of binary strings of length n where “0100” is not present as a substring mod 10^9+7.

// Constraints
// 1 ≤ t ≤ 106

// 1 ≤ n ≤ 106 where n is the length of the string.

// Sample Input 1
// 3
// 3
// 4
// 5
// Sample Output 1
// 8
// 15
// 28

int rec(int i, int int last3){
    if(level==n)return 1;    

    int ans=0;

    if(level>=3 && last3==2){       // why no check for 10 because 010 is also 2 ans 10 is also 2 so we have to check when it is after level2
        ans=rec(level+1,5);
    }else{
        ans=rec(level+1, last3<<1|0 &7);
        ans+=rec(level+1, last3<<1|1 &7);
    }
}



// dp transiiton    dp(i, 010)-----+0   -> dp(i+1, 01000) //invalid statt
                            // --------+1   -> dp(i+1, 0101) ans will back to its origna l value    0101 =5    ---->+0 dp(i+1,1010)  left shift of 5 01010 or 0=>01010 but we have to track of last three bit only so and with 7 01010 &&111=> 010    similarlast3<<1|0 &7
                                                                                                            //    ---->+1 dp(i+1,1011)    left shift of 5 01010 or 1=>01011 but we have to track of last three bit only so and with 7 01011 &&111=> 011    similarlast3<<1|0 &7