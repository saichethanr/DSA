package Restart;

import java.util.*;

class smallest_value_of_rearranged_number {
    public long smallestNumber(long num) {
        boolean isNegative = num < 0;

        if (isNegative) {
            num = -num;
        }

        List<Integer> digits = getSortedDigits(num);

        long ans = 0;

        if (!isNegative) {

            for (int i = 0; i < digits.size(); i++) {
                if (digits.get(i) != 0) {
                    ans = digits.get(i);
                    digits.remove(i);
                    break;
                }
            }

            for (int digit : digits) {
                ans = ans * 10 + digit;
            }
        } else {

            Collections.reverse(digits);

            for (int digit : digits) {
                ans = ans * 10 + digit;
            }

            ans = -ans;
        }
        return ans;
    }


    private static List<Integer> getSortedDigits(long num) {
        List<Integer> digits = new ArrayList<>();
        while (num > 0) {
            digits.add((int) (num % 10));
            num /= 10;
        }
        Collections.sort(digits);
        return digits;
    }
}
