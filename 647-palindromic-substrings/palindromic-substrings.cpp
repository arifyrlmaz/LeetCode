
long long fp(long long a, long long b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b % 2 != 0)
        {
            result = (result * a) % 1000000007;
        }
        a = (a * a) % 1000000007;
        b = b / 2;
    }
    return result % 1000000007;
}
class Solution {
public:
    long long countSubstrings(string s) {
        long long p = 29;
    long long n = s.size();
    long long mod = 1000000007;
    vector<long long> hashes(n + 2), hashes2(n + 2);
    vector<long long> rightprefix(n + 2), leftprefix(n + 2);
    long long ans = 0;
    long long a;
    long long l, r, mid;
    long long invl, invr;

    for (long long i = 1; i <= n; i++)
    {
        hashes[i] = (s[i - 1] - 'a' + 1) * (fp(p, i - 1)) % mod;
        rightprefix[i] = (rightprefix[i - 1] + hashes[i]) %mod;

        hashes2[n - i+1] = (s[n - i] - 'a' + 1) * (fp(p, i - 1)) % mod;
        leftprefix[n - i+1] = (leftprefix[n - i + 2] + hashes2[n - i+1]) % mod;
    }

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = i + 1; j <= n; j++)
        {

            a = j - i;
            if (a % 2 == 0)
            {
                mid = i + a / 2;
                invl = fp(p, n - mid);
                invl = fp(invl, mod - 2);
                l = (((leftprefix[i] - leftprefix[mid] + mod)%mod) * invl) % mod;
                invr = fp(p, mid - 1);
                invr = fp(invr, mod - 2);
                r = (((rightprefix[j] - rightprefix[mid] + mod)%mod) * invr) % mod;
            }
            else
            {
                mid = i + a / 2;
                invl = fp(p, n - mid-1);
                invl = fp(invl, mod - 2);
                l = ((leftprefix[i] - leftprefix[mid + 1]+ mod) * invl) % mod;
                invr = fp(p, mid-1);
                invr = fp(invr, mod - 2);
                r = ((rightprefix[j] - rightprefix[mid]+mod) * invr) % mod;
            }
            if (l == r)
            {
                ans++;
            }
        }
    }
    return ans+n;
    }
};