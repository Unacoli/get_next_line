#include "get_next_line.h"

int main()
{
	printf("%s\n", ft_strnjoin("babar", "chocolat", 3));
	printf("%s\n", ft_strjoin("babar", "chocolat"));
	printf("%s\n", ft_strnjoin("babar", "ch", 42));
	printf("%s\n", ft_strjoin("babar", "ch"));
	printf("%s\n", ft_strnjoin("babar", "", 42));
	printf("%s\n", ft_strjoin("babar", ""));
}	
