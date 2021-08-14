#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int find_part ( int* arr, int size )
{
        int sum = 0, i, j;
        for ( i = 0; i < size; i++ ) {
                sum += arr[i];
        }

        bool btabl[sum / 2 + 1][size + 1];
        for ( i = 0; i < size + 1; i ++ ) {
                btabl[0][i] = true;
        }
        for ( i = 1; i < sum / 2 + 1; i++ ) {
                btabl[i][0] = false;
        }

        for ( i = 1; i < sum / 2 + 1; i++ ) {
                for ( j = 1; j < size + 1; j++ ) {
                        if ( i - arr[j - 1] >= 0 ) {
                                btabl[i][j] = ( btabl[i][j - 1] || btabl[i - arr[j - 1]][j - 1] );
                        } else {
                                btabl[i][j] = btabl[i][j - 1];
                        }
                }
        }

        bool part_exists = btabl[sum / 2][size];
        bool is_sum_even = sum % 2 == 0;
        int result;

        if ( part_exists ) {
                if ( is_sum_even ) {
                        result = 0;
                } else {
                        result = 1;
                }
        } else {
                i = sum / 2;
                while ( !btabl[i][size] ) {
                        i--;
                }
                result = ( sum / 2 - i ) * 2;
                if ( !is_sum_even ) {
                        result += 1;
                }
        }
        return result;
}

int main()
{
        int size;
        scanf ( "%d", &size );

        int rocks[size];
        if ( size == 1 ) {
                int n;
                scanf ( "%d", &n );
                printf ( "%d\n", n );
                return 0;
        } else if ( size == 2 ) {
                int n1, n2;
                scanf ( "%d%d", &n1, &n2 );
                printf ( "%d\n", ( n1 > n2 ? n1 - n2 : n2 - n1 ) );
                return 0;
        } else {
                char weights[10000 * size];
                scanf ( "\n%[^\n]s", weights );

                char* token = strtok ( weights, " " );
                int i = 0;
                while ( token ) {
                        rocks[i++] = atoi ( token );
                        token = strtok ( NULL, " " );
                }

                int part = find_part ( rocks, size );
                switch ( part ) {
                case 0:
                        printf ( "0\n" );
                        break;
                case 1:
                        printf ( "1\n" );
                        break;
                default:
                        printf ( "%d\n", part );
                }

                return 0;
        }
}
