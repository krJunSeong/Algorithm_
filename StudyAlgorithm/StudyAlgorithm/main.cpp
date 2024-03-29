#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <algorithm>
#include <string>
#include <random>
#include <set>
#include <queue>

using namespace std;

float Random(int i)
{
    float ans = 0;

    srand(time(NULL));
    
    ans = rand() % i;

    return ans;
};
class parent
{
public:
    parent()
    {
        cout << " parent create " << endl;
    }

    virtual void pv()
    {
        cout << "parent" << endl;
    }
};

class child : public parent
{
public:
    child()
    {
        cout << " child create " << endl;
    }

    virtual void pv()
    {
        cout << "child" << endl;
    }
};
struct FloatXY
{
    float x;
    float y;

    FloatXY(float a, float b)
    {
        x = a;
        y = b;
    }
};

void Test1()
{
    int n = 360;
    float x = 0, y = 0;
    float theta = 0, radius = 0.5f;
    vector<FloatXY> vertices;
    FloatXY center = FloatXY(0.0f, 0.0f);

    for (int i = 0; i < n; i++)
    {
        float temp = cos(theta);
        float temp2 = sin(theta);
        x = cos(theta) * radius + center.x;
        y = sin(theta) * radius + center.y;

        vertices.emplace_back(x, y);

        theta -= (360 / n);

        x = cos(theta) * radius + center.x;
        y = sin(theta) * radius + center.y;
        float demp = cos(theta);
        float demp2 = sin(theta);

        vertices.emplace_back(x, y);

        vertices.emplace_back(center.x, center.y);
    }
}

void PointTest()
{
    int i = 1;
    int* p = &i;
    int* p2 = p;
    int** pp = &p;

    cout << "i: " << i << endl;
    cout << "&i: " << &i << endl;

    cout << "\np: " << p << endl;
    cout << "*p: " << *p << endl;
    cout << "&p: " << &p <<  endl;
    cout << "&(*p): " << &(*p) << endl;

    cout << "\n p2: " << p2 << endl;
    cout << "*p2: " << *p2 << endl;
    cout << "&p2: " << &p2 << endl;
    cout << "&(*p2): " << &(*p2) << endl;

    cout << "\n pp: " << pp << endl;
    cout << "*pp: " << *pp << endl;

    /*
        포인터:
            - 변수의 주소값을 저장하는 변수

        테스트 내용: 굳이 이중 포인터를 사용할 필요가 있는가?

        포인트 하나 더 만들어서 p2 = p 하면 같은 곳을 가리키는데.
    */
}

void RangeFor()
{
    vector<int> a;
    
    for(int i = 0; i < 5; i++)
        a.push_back(i);

    for(int i : a)
        cout << i << endl;

    for (int i : a)
        i = 10;

    for (int i : a)
        cout << i << endl;

    vector<int*> b;

   // for(int*& i : b)
    //{
    //    i = new int(1);
    //}

    for(int* i : b)
        *i = 10;

    for(int* i : b)
        cout << *i << endl;

}

class TestVirtualFunctionParent
{
public:
    TestVirtualFunctionParent(){cout << "p 생성자" << endl;};
    ~TestVirtualFunctionParent(){};

    virtual void test(){ cout << "parent"<< endl;}
};

class TestVirtualFunctionChild1 : public TestVirtualFunctionParent
{
public:
    TestVirtualFunctionChild1(){ cout << "c1 생성자" << endl; };
    ~TestVirtualFunctionChild1(){};
    virtual void test() { cout << "child1" << endl; }
};

class TestVirtualFunctionChild2 : public TestVirtualFunctionParent
{
public:
    TestVirtualFunctionChild2() { cout << "c2 생성자" << endl; };
    ~TestVirtualFunctionChild2() {};
    virtual void test() { cout << "child2" << endl; }
};


void staircase(int n) {
    for (int i = 0; i < n; i++)
    {
        // 3 2 1 0
        //                 4 - 1 2 3 4
        for (int j = 0; j < n - (1 + i); j++)
            cout << "1";

        // 1 2 3 4
        // 4 - 3 = 1
        // 4 - 2 = 2
        // 4-  1 = 3

        //              1. 4 - 3 ( n - i + 1)
        //              2. 4 - 2     
        //              3. 4 - 1
        //              4. 4 - 0
        for (int k = 0; k < n - (n - (i + 1)); k++)
            cout << "#";

        cout << endl;
    }

}

void miniMaxSum(vector<int> arr)
{
    sort(arr.begin(), arr.end());

    long long maxSum = 0;
    long long minSum = 0;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        minSum += arr[i];
    }

    for (int i = 1; i < arr.size(); i++) 
    {
        int temp =arr[i];
        maxSum += temp;
    }

    cout << minSum << " " << maxSum;
    /*
        vector<int> test;
    test.push_back(256741038);
    test.push_back(623958417);

    test.push_back(467905213);
    test.push_back(714532089);
    test.push_back(938071625);

    miniMaxSum(test);
    */
}

bool table[10001] = { false, };

int d(int inputNum)
{
    int num = inputNum;

    while (inputNum > 0)
    {
        num += inputNum % 10;
        inputNum /= 10;
    }

    return num;
}

void SelfNumber()
{
    int num = 0;
    for (int i = 1; i < 10001; i++)
    {
        num = d(i);
        if( num < 10001) table[num] = true;
    }

    for(int i = 1; i < 10001; i++)
    {
        if(!table[i]) cout << i << endl;
    }
}

void HanSu()
{
    /*
        문제
            어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다.
        등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. N이 주어졌을 때,
        1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
        

        입력
            첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.
        
        출력
            첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

        입력    출력
        --------------------
        110     99
        1       1
        210     105
        1000    144
        500     119
    */
    using namespace std;
    
    int inputNum;
    cin >> inputNum;

    // 100 미만이면, 숫자 그대로 출력
    if(inputNum < 100)
    {
        cout << inputNum << endl;
        return;
    }

    // 100 이상이라면

    int ans = 99;
    // 123, 2- 1, 3 - 2
    // 10의 자리 - 100의 자리  , 1의자리 - 10의 자리
    // 중간 - 뒷, 뒷 - 중간
    // 123 % 10 = 3
    // 123 % 100 = 23
    // 12 % 10 = 2

    // 순서.
    //      100부터 ~ N까지 ++하면서 돌리는 게 목적임.
    //      1. 100을 1개씩 쪼개서 인수에 넣어준다.
    //      2. 넣은 인수끼리 뺄셈을 해서 맞는지 확인한다.
    //      3. 동일하면 ans++,
    //      4. 그리고 100++을 해준다.
    if(inputNum == 1000) inputNum = 999;

    int countNum = 100;
    while(countNum <= inputNum)
    {
        int temp = countNum;

        int one     = temp % 10;
        temp /= 10;

        int ten     = temp % 10;
        temp /= 10;

        int hund   = temp % 10;

        if((ten - hund) == (one - ten)) ans++;

        countNum++;
    }
    
    cout << ans << endl;
}

void PrintASCII()
{
    char ch;
    cin >> ch;

    printf("%d", ch);
    //cout << (int)ch;
}

void PrintNumbersSum()
{
    using namespace std;

    int first = 0;
    string second;

    cin >> first;       // 1 <= N <= 100, 숫자의 개수
    cin >> second;      // 숫자 N개가 공백없이 주어진다.
    
    int ans = 0;

    for(int i = 0; i < first; i++)
    {
       ans += (second[i] - '0');
    }
    
    // print: 입력으로 주어진 숫자 N개의 합
    cout << ans << endl;
}

void TimeSplit()
{
    
string s = "91:23:45AM";

int hh = (s[0] - '0') * 10 + (s[1] - '0');

//int b = a[0] - '0' * 10;
//int c = a[1] - '0';

printf("%02d", hh);

//cout << hh << endl;

}

void FindABC()
{
    using namespace std;

    string s;
    cin >> s;

    vector<int> arr(26);

    // 26개 전부 -1 초기화
    for(int i = 0; i < arr.size(); i++) arr[i] = -1;

    for(int i = 0; i < s.size(); i++)
    {
        int temp = s[i] - 'a';

        if(arr[temp] > -1) continue;
        arr[temp] = i;
    }
    
    for(int i = 0; i< arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

void StringRoop()
{
    using namespace std;
    
    int testCase = 0;
    int roop = 0;
    string s;

    cin >> testCase;
    for(int i = 0; i < testCase; i++)
    {
        cin >> roop;
        cin >> s;

        string ans = "";

        for(int i = 0; i < s.size(); i++)
        {
            for(int j = 0; j < roop; j++)
            {
                ans += s[i];
            }
        }

        cout << ans << endl;
    }

}

void WordStudy()
{
    /*
        문제
            알파벳 대소문자로 된 단어가 주어지면, 
            이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
            단, 대문자와 소문자를 구분하지 않는다.
        
        입력
            첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다.
            주어지는 단어의 길이는 1,000,000을 넘지 않는다.
        
        출력
            첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.
            단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
        
        예제 입력 1     예제 출력 1
        Mississipi     ?

        예제 입력 2     예제 출력 2 
        zZa            Z

        예제 입력 3     예제 출력 3 
        z              Z

        예제 입력 4     예제 출력 4 
        baaa           A
    */

    using namespace std;

    int arr[26] = {0,};
    string ans = "";
    string InputS = "";

    cin >> InputS;
    
    for(int i = 0; i < InputS.size(); i++)
    {
        int temp = InputS[i];

        if(temp < 97) 
        {
            InputS[i] = char(temp + 32);
            temp += 32;
        }

        arr[temp - 'a'] ++;
    }


    // 카운트 해서 제일 많이 쓰인 알파벳 찾는 곳.
    int maxNum = 0;         // 최대 수
    for(int i = 0; i < 26; i++)
    {
        if(maxNum < arr[i])
        {
            maxNum = arr[i];
            ans = char(i + 'A');
        }
    }

    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if(maxNum == arr[i]) count++;
    }

    if (count >= 2) ans = '?';

    cout << ans << endl;

    // space    32
    //  a       97
    //  A       65
    //cout << (int)'a'<< endl;
    //cout << (int) ' ' << endl;
    //cout << char('A' + ' ') << endl;
}

void WordCount()
{
    using namespace std;

    string inputS;
    int count = 0;

    while (cin >> inputS)
    {
        count++;
    }

    cout << count;

}

void Sangsu()
{
    char num1[5];
    char num2[5];

    cin >> num1;
    cin >> num2;

    int jari = 1;
    int temp1 = 0;
    for(int i = 0; i < strlen(num1); i++)
    {
        temp1 += (num1[i] - '0') * jari;
        jari *= 10;
    }

    jari = 1;
    int temp2 = 0;
    for (int i = 0; i < strlen(num2); i++)
    {
        temp2 += (num2[i] - '0') * jari;
        jari *= 10;
    }
    
    int ans = temp2;
    temp1 > temp2? ans = temp1: 0;

    cout << ans;
    
    //int num2Count = strlen(num2);
    // sizeof: 실제 차지하고 있는 메모리
    // strlen: 문자열의 길이를 구한다. 이 때 길이는 NULL 문자를 만날 때까지의 문자수를 센다.
}

void Dial()
{
    int arr[26] = { 3,3,3,
                    4,4,4,
                    5,5,5,
                    6,6,6,
                    7,7,7,
                    8,8,8,8,
                    9,9,9,
                    10,10,10,10};

    
    string inputS;
    cin >> inputS;

    int ans = 0;
    for(int i = 0; i < inputS.size(); i++)
    {
        int temp = inputS[i] - 'A';
        ans += arr[temp];
    }

    cout << ans;
}

void CroatiaABC()
{
    string wordList[8] = {"c=", "c-",
                           "dz=", "d-",
                           "lj", "nj",
                           "s=", "z="};

    string inputString;
    cin >> inputString;

    string temp = "";
    int sum = 0;
    int sumWordCount = 0;

    // inputString 처음부터 끝까지 진행
    for(int i = 0; i < inputString.size() - 1; i++)
    {
        // wordlist [0] ~ [8] 까지 반복
        for(int j = 0; j < 8; j++)
        {
            temp = "";
            int wordCount = wordList[j].size();

            if(i + wordCount > inputString.size()) continue;

            for(int k = 0; k < wordCount; k++)
            {
                temp += inputString[i+k];
            }

            if(temp == wordList[j])
            {
                sum++;
                sumWordCount += wordCount;
                i += (wordCount - 1);
            }
        }
    }

    int nokori = inputString.size() - sumWordCount;
    sum += nokori;

    cout << sum << endl;
}


void GroupWordCheck()
{
    int lineCount = 0;
    int abc[26] = {0,};
    int ans = 0;
    string inputStringArr[100];

    cin >> lineCount;
    
    for(int i = 0; i < lineCount; i++)
    {
        cin >> inputStringArr[i];
    }

    bool chk = false;
    for(int k = 0; k < lineCount; k++)
    {
        chk = true;

        for(int i = 0; i < inputStringArr[k].size() - 1; i++)
        {
            // 같은 경우와 다른 경우만 처리. 그러면 if문 2개로 처리 가능.
            if(inputStringArr[k][i] != inputStringArr[k][i+1])
            {
                abc[inputStringArr[k][i] - 'a'] = 1;

                // 다른데, 뒷자리에 있는 것이 이미 작동됐던 것이다? 그럼 X
                if(abc[inputStringArr[k][i+1] - 'a'] > 0)
                {
                    chk = false;
                    break;
                }
            }
        }

        for(int m = 0; m < 26; m++) abc[m] = 0;

        if (chk) ans++;
    }

    cout << ans;
}

void BreakEvenPoint()
{
    /*
    월드전자는 노트북을 제조하고 판매하는 회사이다. 노트북 판매 대수에 상관없이 매년 임대료, 재산세, 보험료, 급여 등 
    A만원의 고정 비용이 들며, 한 대의 노트북을 생산하는 데에는 재료비와 인건비 등 총 B만원의 가변 비용이 든다고 한다.
    
    예를 들어 A=1,000, B=70이라고 하자. 이 경우 노트북을 한 대 생산하는 데는 총 1,070만원이 들며, 열 대 생산하는 데는 총 1,700만원이 든다.
    
    노트북 가격이 C만원으로 책정되었다고 한다. 일반적으로 생산 대수를 늘려 가다 보면 어느 순간 총 수입(판매비용)이 총 비용(=고정비용+가변비용)보다 많아지게 된다. 
    최초로 총 수입이 총 비용보다 많아져 이익이 발생하는 지점을 손익분기점(BREAK-EVEN POINT)이라고 한다.
    
    A, B, C가 주어졌을 때, 손익분기점을 구하는 프로그램을 작성하시오.
    

    A: 고정 비용
    B: 가변 비용
    C: 노트북 가격

    입력
    첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 21억 이하의 자연수이다.
    
    출력
    첫 번째 줄에 손익분기점 즉 최초로 이익이 발생하는 판매량을 출력한다. 손익분기점이 존재하지 않으면 -1을 출력한다.
    
    예제 입력 1         예제 출력 1 
    1000 70 170          11
    
    예제 입력 2         예제 출력 2
    3 2 1               -1
     
    예제 입력 3         예제 출력 3
    210 000 000 0 9 10     210 000 000 1
    */

    long long a;          // 고정비용
    long long b;          // 가변비용
    long long c;          // 수입가격

    cin >> a >> b >> c;
    int cnt = 0;
    
    if(b > c) cnt = 0;
    else cnt = (a / (c - b)) + 1;

    cout << cnt;
}

void FindHide()
{
    int hide = 1;
    int cnt = 1;
    int sum = 0;
    int n = 0;

    cin >> n;

    while(n >= hide)
    {
        sum += 6;
        hide += sum;
        cnt++;
    }

    cout << cnt;
}

void BunsuFind()
{
    int N = 0;          // 찾을 번호
    int cnt = 0;        // 몇 번째 대각선인가?
    int sumCnt = 0;     // 원소 개수 누적

    cin >> N;
    while(true)
    {
        cnt++;
        sumCnt += cnt;
        
        if(sumCnt >= N) break;
    }
    int top = 0;
    int bottom = 0;
    if(cnt % 2 == 1)                // 홀수일 때
    {
        top = sumCnt - N + 1;
        bottom = cnt + 1 - top;
    }
    else                            // 짝수일 때
    {
        bottom = sumCnt - N + 1;
        top = cnt + 1 - bottom;
    }

    cout << top << "/" << bottom;
}

void SnailUp()
{
    int a;
    int b;
    int v;
    int cnt = 0;

    cin >> a;
    cin >> b;
    cin >> v;

    cnt = (v-b) / (a-b);

    if((v-b) % (a-b)) cnt++;

    cout << cnt;
}

void ACMHotel()
{
    int t;
    int h, w, n;
    int ans;

    cin >> t;

    for(int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;

        if(n % h == 0) ans = h * 100 + (n / h);
        else ans = (n % h) * 100 + (n / h) + 1;

        cout << ans << endl;
    }

}

void BeDonePresident()
{
    int testCase = 0;
    int floor = 0;
    int num = 0;
    int arr[15][15] = {0,};

    cin >> testCase;

    for(int t = 0; t < testCase; t++)
    {
        cin >> floor >> num;

        for(int i = 0; i <= floor; i++)
        {
            arr[i][1] = 1;
        }

        int cnt = 1;
        for(int i = 1; i <= num; i++)
        {
            arr[0][i] = cnt;
            cnt++;
        }

        // floor
        for(int f = 1; f <= floor; f++)
        {
            // num
            for(int n = 2; n <= num; n++)
            {
                arr[f][n] = arr[f][n-1] + arr[f-1][n];
            }
        }

        cout << arr[floor][num] << endl;
    }
}

void SugarDelivery()
{
    int cnt = 0;
    int N = 0;

    cin >> N;
    
    if(!(N%5)) 
    {
        cout << N/5;
        return;
    }
    
    while( N > 0)
    {
        N -= 3;
        cnt++;

        if(!(N%5)) 
        {
            cnt += N/5;
            break;
        }
    }

    if(N < 0) cout << -1;
    else cout << cnt;
}

void SumBigNum()
{
    string a;
    string b;
    string ans;

    cin >> a >> b;

    int chai = a.size() - b.size();
    chai = abs(chai);

    int strSize = a.size();
    if(strSize < b.size()) strSize = b.size();

    for(int i = 0; i < chai; i++)
    {
        if(a.size() < b.size()) a.insert(0, "0");
        else b.insert(0,"0");
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;
    for(int i = 0; i < strSize; i++)
    {
        a[i];
        int aa = a[i] - '0';
        int bb = b[i]  - '0';
        int temp = aa + bb + carry;

        if(temp > 9)
        {
            carry = 1;
            temp -= 10;
        }
        else carry = 0;

        ans += (temp + '0');
    }

    if(carry) ans += '1';

    reverse(ans.begin(), ans.end());

    cout << ans;
}

void FindSosu()
{
    int N;
    cin >> N;
    
    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        int inputNum;
        cin >> inputNum;

        if(inputNum == 1) continue;

        bool ChkSosu = true;
        for(int j = 2; j < inputNum; j++)
        {
            if(inputNum % j) ChkSosu = true;
            else
            {
                ChkSosu = false;
                break;
            }
        }

        if(ChkSosu) ans++;
    }

    cout << ans;
}

void Sosu()
{
    int M;
    cin >> M;

    int N;
    cin >> N;

    int sum = 0;
    int min = 11111;
    for (int i = M; i <= N; i++)
    {
        if (i == 1) continue;

        bool ChkSosu = true;
        for (int j = 2; j < i; j++)
        {
            if (i % j) ChkSosu = true;
            else
            {
                ChkSosu = false;
                break;
            }
        }

        if (ChkSosu)
        {
            sum += i;

            if(i < min) min = i;
        }
    }

    if(!sum) cout << -1;
    else
    {
        cout << sum << endl;
        cout << min;
    }
}

void SoinsuBunhae()
{
    int N;
    cin >> N;

    vector<int> ans;
    while(N > 1)
    {
        for(int i = 2; i <= N; i++)
        {
            if(N % i == 0)
            {
                N = (N/i);
                ans.push_back(i);
                break;
            }
        }
    }

    sort(ans.begin(), ans.end());

    for(int i : ans)
        cout << i << endl;
}

void Sosu2()
{
    int M;
    int N;
    int sqrtNum;

    cin >> M >> N;

    if (M == 1) M++;
    if (M == 2 && M <= N)
    {
        cout << 2 << endl;
        M++;
    }
    if (M == 3 && M <= N)
    {
        cout << 3 << endl;
        M++;
    }

    for (int i = M; i <= N; i++)
    {
        if(i % 2 == 0) continue;
        sqrtNum = sqrt(i);

        for (int j = 2; j <= sqrtNum; j++)
        {
            if(!(i % j)) break;    

            if (j == sqrtNum) cout << i << '\n';
        }
    }
}

void Sosu2_2()
{
    int M;
    int N;

    cin >> M >> N;

    vector<bool> arr(N+1, false);

    // Create
    for(int i = 2; i <= N; i++)
    {
        arr[i] = true;
    }


    //int sqrtNum = sqrt(N);
    for (int i = 2; i * i <= N; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        for (int j = i + i; j <= N; j += i)
        {
            arr[j] = 0;
        }
    }

    // cout
    for(int i = M; i <= N; i++)   
    {
        if(arr[i]) cout << i << '\n';
    }
}

void BertGonjun()
{
    int M;
    int N = 1;

    while(true)
    {
        int M;
        cin >> M;

        if(!M) break;

        N = M * 2;

        vector<bool> arr((M * 2) + 1, false);

        int cnt = 0;

        // Create
        for (int i = 2; i <= N; i++)
        {
            arr[i] = true;
        }


        //int sqrtNum = sqrt(N);
        for (int i = 2; i * i <= N; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }
            for (int j = i + i; j <= N; j += i)
            {
                arr[j] = 0;
            }
        }

        // cout
        for (int i = M + 1; i <= N; i++)
        {
            if (arr[i]) cnt++;
        }

        cout << cnt << endl;
    }
}

void GoldBath()
{
    int testCase;
    int N;
    cin >> testCase;

    bool arr[10001];

    // 1. 채로 2 ~ 10,000 까지 소수를 걸러낸다
    // if(i ==  소수)
    // 2. 2부터 시작해서 2 + (자신 + n-a)까지 반복한다.
    //           if( 윗 공식 > n) break;
    // 3. 3... 4.... 루프한다. 

    // 1. 채 만들기
        // 배열 초기화
    for (int i = 2; i <= 10000; i++)
    {
        arr[i] = 1;
    }
    

    for (int i = 2; i * i <= 10000; i++)
    {
        if (arr[i] == 0) continue;

        for (int j = i + i; j <= 10000; j += i)
        {
            arr[j] = 0;
        }
    }

    // 알고리즘 수행
    for(int t = 0; t < testCase; t++)
    {
        cin >> N;

        int ansA = 0;
        int ansB = 0;
        for(int i = N * 0.5; i >= 2; i--)
        {
            if(arr[i] == 0) continue;

            for(int j = N * 0.5; j < N; j++)
            {
                if(arr[j] == 0) continue;

                if(i + j == N) 
                {
                    ansA = i;
                    ansB = j;
                    break;
                }
            }
            if(ansA > 0) break;
        }

        cout << ansA << " " << ansB << "\n";
    }

}

int Factorial(int N)
{
    if(N <= 1) return 1;
    return N * Factorial(N-1);

    /*
    int n = 0;
    cin >> n;
    n = Factorial(n);
    cout << n;*/
}

int Pibonachi(int N)
{
    if(N == 0) return 0;
    if(N == 1) return 1;

    return Pibonachi(N-1) + Pibonachi(N-2);
}



int WhatIsRecursiveFunction(int N)
{
    // 다시 사용할 때는 전역변수로 설정할 것
    static int cnt = 0;
    static string str = "";

    if(N == 0)
    {
        printf("%s\"재귀함수가 뭔가요?\"\n", str.c_str());
        printf("%s\"재귀함수는 자기 자신을 호출하는 함수라네\"\n", str.c_str());
        
        for(int i = 0; i <= cnt; i++)
        {
            printf("%s라고 답변하였지.\n", str.c_str());
            str.erase(0,4);
        }
        return 0;
    }

    {
        printf("%s\"재귀함수가 뭔가요?\"\n", str.c_str());
        printf("%s\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n", str.c_str());
        printf("%s마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n", str.c_str());
        printf("%s그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n", str.c_str());
        
        str += "____";
        cnt++;
        return WhatIsRecursiveFunction(--N);
    }

    /*
    int main()
    {
        int n;
        cin >> n;

        printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");

        WhatIsRecursiveFunction(n);
    }
    */

}


void StarRecursiveFunction(int i, int j, int n)
{
        if (i / n % 3 == 1 && j / n % 3 == 1)
        {
            cout << " ";
        }
        else if (n / 3 == 0) {
            cout << "*";
        }
        else {
            StarRecursiveFunction(i, j, n / 3);
        }
        /*
        int main()
        {
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) 
            {
                for (int j = 0; j < n; j++) 
                {
                    StarRecursiveFunction(i, j, n);
                }
                cout << '\n';
            }
        }
        */
}


//        원판개수,         출발지,   목적지,   경유지
// N개의 원판을, startPoint에서 defstnation으로 이동하는데, 보조로 reference를 사용하겠다.
void hanoi(int N, int startPoint, int destnation, int reference)
{
    // 이동할 원반의 수가 1개라면?
    if(N == 1)
    {
        cout << startPoint << ' ' << destnation << '\n';
        return;
    }
    else
    {
        // A -> C로 옮긴다고 가정
        // Step 1: N-1개를 A에서 B로 이동 (= start 지점의 N-1개의 원판을 경유지(def) 지점으로 이동)
        hanoi(N - 1, startPoint, reference, destnation);
        
        // Step 2: 1개를 A에서 C로 이동    (= start 지점의 N번째 원판을 목적지(def) 지점으로 옮긴다)
        cout << startPoint << ' ' << destnation << '\n';

        // Step 3: N-1개를 B에서 C로 이동 (= 경유지(ref) 지점의 N-1개의 원판을 목적지(def) 지점으로 옮긴다
        hanoi(N - 1, reference, destnation, startPoint);
    }
    /*
    int main()
    {
        int n;
        cin >> n;
    
        cout << (int)pow(2,n) -1 << '\n';
        hanoi(n, 1, 3, 2);
    
        return 0;
    }
    
    */
}

void Blackjack()
{
    int N;
    int M;

    cin >> N >> M;

    vector<int> vNum;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        vNum.push_back(temp);
    }

    sort(vNum.begin(), vNum.end(), greater<int>());

    // 제일 큰 수 + 그 다음으로 큰 수

    // 2번째
    int nowNum = 0;
    int maxNum = 0;
    for(int k = 0; k < vNum.size() - 2; k++)
    {
        for(int i = k + 1; i < vNum.size() - 1; i++)
        {
            nowNum = vNum[k] + vNum[i];

            if(nowNum >= M) continue;

            // 나머지 수 구하는 곳
            for(int j = i + 1; j < vNum.size(); j++)
            {
                nowNum += vNum[j];

                if(nowNum == M) 

                {
                    cout << nowNum;
                    return;
                }
                else if( maxNum < nowNum && nowNum < M)
                {
                    maxNum = nowNum;
                }

                nowNum -= vNum[j];
            }
        }
    }

    cout << maxNum;
}

void BunhaeHab()
{
    int quest;
    cin >> quest;

    for(int i = 1; i < quest; i++)
    {
        string temp;
        temp = to_string(i);

        int itemp = i;
        for(char a : temp)
        {
            itemp += (a - '0');
        }

        if(itemp == quest)
        {
            cout << i;
            return;
        }
    }
    //1. 수를 하나 받는다
    //2. 받은 수의 생성자을 구한다.
    //3. 출력한다.

    cout << 0;
}

void Dungchi()
{
    vector<pair<int, int>> a;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int x;
        int y;

        cin >> x >> y;

        a.push_back(make_pair(x,y));
    }

    for(int i = 0; i < n; i++)
    {
        int grade = 1;

        for(int j = 0; j < n; j++)
        {
            if( i == j ) continue;

            if(a[i].first < a[j].first && a[i].second < a[j].second) 
                grade++;

        }

        cout << grade;

        if(i < (n-1)) cout << ' ';
    }
}

void ChessPhan()
{
    int n, m;
    int cnt = 0;
    char c, nc;
    cin >> n;
    cin >> m;

    string s;
    cin >> s;
    cout << s;
    //for(int i = 0; i < n; i++)
    //{
    //    for(int j = 0; j < m-1; j++)
    //    {
    //        char c;
    //        cin >> c;

    //        
    //    }
    //}

    cout << cnt;
}

void Wizang()
{
    vector<vector<string>> clothes = { {"yellow_hat","headgear"},{"blue_sunglasses", "eyewear"},{"green_turban", "headgear"} };
    map<string, int> map;

    int answer = 1;

    for (auto i : clothes)
        map[i[1]]++;

    for (auto i : map)
        answer *= i.second;

    cout << answer << endl;
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
} //내림차순

bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
} //내림차순

vector<int> BestAlbum()
{
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    map<string, int> genresSum;               // 각 장르 : 플레이수
    map<string, vector<int>> genresUniqueNum; // 각 장르 : 고유번호

    vector<int> answer;
    map<string, int> sumGenresPlays;          // 장르 : 총플레이수
    map<string, vector<pair<int, int>>> map2; // 장르 : vector<고유번호, 재생수>

    // 1. 장르 : 플레이총합
    for (int i = 0; i < genres.size(); i++)
    {
        sumGenresPlays[genres[i]] += plays[i];    // 장르 : 플레이총합
        map2[genres[i]].push_back({ i, plays[i] }); // 장르 : vector<고유번호, 재생수>
    }

    // 2. 장르: 플레이총합 벡터에 옮겨서 내림차순 정렬
    vector<pair<string, int>> vGenresPlaySum(sumGenresPlays.begin(), sumGenresPlays.end());

    // 2-1) 장르 : 플레이총합 정렬
    sort(vGenresPlaySum.begin(), vGenresPlaySum.end(), cmp);

    // 2-2) 장르 : vector<고유번호, 재생수>, 재생수 기준 정렬
    for (auto& i : map2)
    {
        sort(i.second.begin(), i.second.end(), cmp2);
    }

    // 3. 장르별 재생순위를 구했으니, vGenresPlaySum의 장르(first)를 받아서
    //    map2[장르]의 벡터[0], [1]을 answer에 넣어준다.
    for (auto i : vGenresPlaySum)
    {
        if (map2[i.first].size() < 2)
            answer.push_back(map2[i.first][0].first);
        else
        {
            answer.push_back(map2[i.first][0].first);
            answer.push_back(map2[i.first][1].first);
        }
    }

    for (auto i : answer)
        cout << i << endl;

    return answer;
}

void FunctionDevelope()
{
    vector<int> progresses({ 93, 30, 55 });
    vector<int> speeds({ 1, 30, 5 });
    vector<int> answer;
    queue<int> q;

    // 100 - 프로그레스.size()
    // q에 
    for (int i = 0; i < progresses.size(); i++) {
        if ((100 - progresses[i]) % speeds[i] == 0) {
            q.push((100 - progresses[i]) / speeds[i]);
        }
        else {
            q.push((100 - progresses[i]) / speeds[i] + 1);
        }
    }

    // q가 비어있지 않으면 반복
    while (!q.empty()) {
        int cnt = 1;                // cnt = 1
        int current = q.front();    // 현재: q의 맨앞
        q.pop();                    // q 맨 앞 비워주고

        // q가 비어있지 않고, q의 front가 현재값보다 작다면
        while (!q.empty() && q.front() <= current) {
            cnt++;      // cnt++
            q.pop();    // q 앞에 비워주고
        }
        answer.push_back(cnt);
    }
}

void FunctionDevelopeDay2()
{
    vector<int> progresses({ 93, 30, 55 });
    vector<int> speeds({ 1, 30, 5 });
    vector<int> answer;
    vector<int> q;
    int cnt = 0;

    for (int i = 0; i < progresses.size(); i++)
    {
        if ((100 - progresses[i]) % speeds[i] == 0)
        {
            q.push_back((100 - progresses[i]) / speeds[i]);
        }
        else
            q.push_back((100 - progresses[i]) / speeds[i] + 1);
    }

    int cntNum = 1;
    int curNum;
    while (!q.empty())
    {
        cntNum = 1;
        curNum = q[0];
        q.erase(q.begin());

        while (!q.empty() && q[0] <= curNum)
        {
            cntNum++;
            q.erase(q.begin());
        }

        answer.push_back(cntNum);
    }
}

class A
{
public:
    A(){}
    virtual void Update() { cout << "AUpdate()" << endl;}  
};

class B : public A
{
public:
    B() {}
    void Update() { cout << "BUpdate()" << endl; }
};

class C : public B
{
public:
    C() {}
    void Update() { cout << "CUpdate()" << endl; }
};

int SearchBinary(int item, vector<int> list)
{
    int low = 0;
    int high = list.size()-1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        int guess = list[mid];

        if(guess == item) return mid;

        if(item > guess) low = mid + 1;
        else high = mid - 1;
    }
    
    return -1;

    /*
    int main()
    {
      vector<int> myList{1, 3, 5, 7, 9}; 
      cout << SearchBinary(1, myList);
    }
    */
}

int lowNumInArr(vector<int> arr)
{
    int index = 0;
    int lowNum = INT_MAX;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < lowNum)
        {
            lowNum = arr[i];
            index = i;
        }
    }

    return index;
}

void selectionSort()
{
    vector<int> a{5, 3, 6, 2, 10};
    vector<int> answer;

    int size = a.size();

    for (size_t i = 0; i < size; i++)
    {
        int index = lowNumInArr(a);
        answer.push_back(a[index]);
        a.erase(a.begin() + index);
    }

    
    for(auto i : answer)
        cout << i << " ";
}
vector<int> quickSort(vector<int> inputVector)
{
    if(inputVector.size() < 2) return inputVector;

    int pivot = inputVector[0];
    
    vector<int> lessVector;
    vector<int> greaterVector;

    for(int i = 1; i < inputVector.size(); i++)
    {
        if(inputVector[i] < pivot)
        {
            lessVector.push_back(inputVector[i]);
        }
        else
        {
            greaterVector.push_back(inputVector[i]);
        }
    }

    vector<int> totalLessVector = quickSort(lessVector);
    vector<int> totalGreaterVector = quickSort(greaterVector);

    vector<int> total(totalLessVector);
    total.push_back(pivot);
    
    for(auto i : totalGreaterVector)
        total.push_back(i);

    return total;

    /*
    int main()
    {
        vector<int> temp{11,9,24,3,5,6,7,8};

        vector<int> i = quickSort(temp);

        for(auto k : i)  cout << k << " ";
    }
    */
}

string SearchDragUser()
{
    map<string, vector<string>> graph;
    graph["you"] = {"alice", "bob", "Clare"};
    graph["bob"] = {"anju", "pegy"};
    graph["alice"] = {"pegy"};
    graph["Clare"] = {"tom", "jony"};
    graph["anju"];
    graph["pegy"];
    graph["tom"];
    graph["jony"];

    queue<string> q;

    for (auto& i : graph["you"])
    {
        q.push(i);
    }

    while (q.size())    // q 없을 때까지 반복
    {
        // 마약상이면 리턴
        if (q.front().back() == 'm')
        {
            cout << "범인: " << q.front() << endl;
            return q.front();
        }

        else // 마약상 아니라면 큐에 연관사람 추가
        {
            for (auto& i : graph[q.front()])
            {
                q.push(i);
            }

            q.pop();
        }
    }
    
    //printf(" ");
}

//다익스트라
void graphInit(map<string, map<string, int>>& _graph)
{
    _graph["strat"]["a"] = 6;
    _graph["strat"]["b"] = 2;

    _graph["a"]["fin"] = 1;
    
    _graph["b"]["a"] = 3;
    _graph["b"]["fin"] = 5;
    
    _graph["fin"];
}

void costInit(map<string, int>& _cost)
{
    _cost["a"] = 6;
    _cost["b"] = 2;
    _cost["fin"] = INT_MAX;
}

void parentsInit(map<string, string>& _parents)
{
    _parents["a"] = "start";
    _parents["b"] = "start";
    _parents["fin"] = "";

}

// 코스트가 적은 노드 찾기
string FindLowCostNode(map<string, int> costs, map<string, bool> _processed)
{
    int lowCost = INT_MAX;
    string lowCostNode = "";
    
    for (auto node : costs)             // 비용표
    {
        int cost = costs[node.first];   // for: 현재 노드의 비용

        // 비용표에서 제일 작은 코스트 노드 찾기
        if (cost < lowCost && (_processed[node.first] == false))
        {
            lowCost = cost;
            lowCostNode = node.first;
        }
    }

    return lowCostNode;
}

void djstra()
{
    map<string, int>              costs;
    map<string, string>           parents;

    map<string, map<string, int>> graph;
    map<string, bool> processed;

    // 그래프, 코스트, 부모표 정리
    graphInit(graph); 
    costInit(costs);
    parentsInit(parents);

    string node = FindLowCostNode(costs, processed);
    while (node.size() > 0)
    {
        int cost = costs[node];         // 현재 노드의 비용
        auto edgeNodes = graph[node];   // 현재 노드와 이어진 노드:비용

        for (auto n : edgeNodes)
        {
            int newCost = cost + edgeNodes[n.first];    // ex) 스타트->B 코스트: 2,
                                                        //         B->A   cost: 3, 2+3 = 5
            if (costs[n.first] > newCost)               //     스타트->A 비용> (B까지 코스트 + B->A 비용)
            {
                costs[n.first] = newCost;
                parents[n.first] = node;
            }
        }
        
        processed[node] = true;
        node = FindLowCostNode(costs, processed);
    }

    for (auto i : costs) cout << i.first << ": " << i.second << endl;;
    for (auto i : parents) cout << i.first << ": " << i.second << endl;
}

// 근사 알고리즘
void ApproximationAlgorithm()
{/*
     Err: 간접 참조 잘못됨
        - set_intersection
     set_interction 문제
        - 문제: output Vector에 resize로 인해 "" 잉여가 생김
        - 해결: interction할 때 std::back_inserter(vector3)
        - 이유: Return value
                A std::back_insert_iterator which can be used to add elements to the end of the container c
     해결되는 이유 찾기
          - backInserter의 경우 뒤에서 한두개 더 원소가 들어가서 해결되는 것으로 보임.

          - kone 때 begin()의 경우, "" 때 8 > 7
          -         back_inserter, "" 때 8 > 9, 
  */              
    vector<string> states_needed{ "mt", "wa", "or", "id", "nv", "ut", "ca", "az" };
    map<string, vector<string>> stations;
    stations["kone"] = {"id", "nv", "ut"};
    stations["ktwo"] = {"wa", "ia", "mt"};
    stations["kthree"] = {"or","nv","ca"};
    stations["kfour"] = {"nv", "ut"};
    stations["kfive"] = {"ca", "az"};

    vector<string> final_stations;

    // 남은 커버쳐야 할 지역들
    while (states_needed.size() > 0)
    {
        string bestStation;
        vector<string> states_covered; // 커버된 지역

        // 커버쳐야 할 지역들 정렬
        for (auto& station : stations)
        {                
            // covered: 남은 지역 중 방송국이 처리가능한 지역
            sort(states_needed.begin(), states_needed.end());
            sort(station.second.begin(), station.second.end());
            vector<string> covered;
            
            set_intersection(states_needed.begin(), states_needed.end(),
                            station.second.begin(), station.second.end(),
                            std::back_inserter(covered));

            // 처리가능 지역 > 방송국 처리지역
            // 이 방송국이 현재의 bestStation보다 더 많은 주를 커버하는가?
            if (covered.size() > states_covered.size())
            {
                bestStation = station.first;
                states_covered = covered;
            }
        }
        
        // 남은 지역에서 커버된 지역들 빼기(개선필요) && 방송국 선정
        for (auto i : states_covered)
            states_needed.erase(std::remove(states_needed.begin(), states_needed.end(), i), states_needed.end());

        // states_needed -= states_covered;
        final_stations.push_back(bestStation);
    }

    for (auto i : final_stations)
        cout << i << endl;
}

int main()
{
    ApproximationAlgorithm();
}

/* map 사용법, #map #map<map> #map<int>

    map<string, vector<pair<string, int>>> a;
    a["start"].push_back({ "A", 1 });
    a["start"].push_back({ "B", 2 });

    cout << a["start"][0].first << " " << a["start"][0].second << endl;
    cout << a["start"][1].first << " " << a["start"][1].second << endl;

    map<string, map<string, int>> mb;
    mb["string"]["a"] = 6;
    mb["string"]["b"] = 8;
    mb["string"].insert({ "c", 9 });

    cout << "a: " << mb["string"]["a"] << endl;
    cout << "b: " << mb["string"]["b"] << endl;

    // 방법 1) mb["string"]["a"] = 6;
    // 방법 2) mb["string"].insert({"c", 9});

    vector
        vector 중복제거
            vector<string> temp;
            temp.erase(unique(temp.begin(), temp.end()), temp.end())
*/