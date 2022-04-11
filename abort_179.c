#include <stdio.h>
#include <stdlib.h>

int n_of_num(int num)
{
    if (num == 0)
        return (1);

    int len  = 0;
    while (num > 0)
    {
        num = num / 10;
        len++;
    }
    return (len);
}

char	*ft_itoa(int n)
{
	int	len;
	char			*p;

	len = n_of_num(n);
	p = calloc(len + 1, sizeof(char));
	if (!p)
		return (0);
	while (len-- > 0)
	{
		p[len] = n % 10 + '0';
		n = n / 10;
	}
	return (p);
}

int sum_of_num(int first, int second)
{
    int fir_n = n_of_num(first);
    int sec_n = n_of_num(second); 

    int fs = first;
    int sf = second;

    while (sec_n-- > 0)
        fs = fs * 10;
    while (fir_n-- > 0)
        sf = sf * 10;
    
    if (fs + second > sf + first)
        return (1);
    else
        return (0);

}

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}


char	*ft_strcat(char *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		sum;
	char	*result;

	sum = 0;
	sum = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * sum + 1);
	if (result == 0)
		return (0);
	i = 0;
	*result = '\0';
	ft_strcat(result, s1);
	ft_strcat(result, s2);
	
	return (result);
}


char *largestNumber(int* nums, int numsSize){
    int out = 0;
    int in;
    int tmp = 0;
    int i = 0;
    char    *result;

    while (out < numsSize)
    {
        in = 0;
        while (in < numsSize)
        {
            //0이면 in + 1이 앞으로 이동.
            if (sum_of_num(nums[in],nums[in + 1]) == 0)
            {
                tmp = nums[in];
                nums[in] = nums[in + 1];
                nums[in + 1] = tmp;
            }
            in++;
        }
        out++;
    }

    while (i < numsSize + 1)
    {
        if (!result)
            result = ft_itoa(nums[i]);
        else
        {
			result = ft_strjoin(result, ft_itoa(nums[i]));
        }
        i++;
    }
	printf("%s",result);
	return (result);
}

int main()
{
    int *nums;
    int num[] ={9,4,1,2,78,4,1,2};
    nums = num;
    largestNumber(nums,7);
}
//버블? 퀵?
//일단 버블로 구현.