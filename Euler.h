//
//  Euler.h
//  ProjectEuler
//

#ifndef __ProjectEuler__Euler__
#define __ProjectEuler__Euler__

#include <iostream>

#include "Utility/Common/Common.h"
#include "Problem0.h"
#include "Problem1.h"
#include "Problem2.h"
#include "Problem3.h"
#include "Problem4.h"
#include "Problem5.h"
#include "Problem6.h"
#include "Problem7.h"
#include "Problem8.h"
#include "Problem9.h"
#include "Problem10.h"
#include "Problem11.h"
#include "Problem12.h"
#include "Problem13.h"
#include "Problem14.h"
#include "Problem15.h"
#include "Problem16.h"
#include "Problem17.h"
#include "Problem19.h"
#include "Problem20.h"
#include "Problem21.h"
#include "Problem22.h"
#include "Problem23.h"
#include "Problem24.h"
#include "Problem25.h"
#include "Problem26.h"
#include "Problem27.h"
#include "Problem28.h"
#include "Problem29.h"
#include "Problem30.h"
#include "Problem31.h"
#include "Problem32.h"
#include "Problem33.h"
#include "Problem34.h"
#include "Problem35.h"
#include "Problem36.h"
#include "Problem37.h"
#include "Problem38.h"
#include "Problem39.h"
#include "Problem40.h"
#include "Problem41.h"
#include "Problem42.h"
#include "Problem43.h"
#include "Problem44.h"
#include "Problem45.h"
#include "Problem46.h"
#include "Problem47.h"
#include "Problem48.h"
#include "Problem49.h"
#include "Problem50.h"
#include "Problem52.h"
#include "Problem55.h"
#include "Problem56.h"
#include "Problem58.h"
#include "Problem62.h"
#include "Problem63.h"
#include "Problem66.h"
#include "Problem71.h"
#include "Problem74.h"
#include "Problem76.h"
#include "Problem77.h"
#include "Problem81.h"
#include "Problem82.h"
#include "Problem83.h"
#include "Problem92.h"

#define SOLVE(x) \
        clock_t t; \
        t = clock(); \
        Problem##x solver; \
        std::cout << solver.solve() << "\n"; \
        std::cout << "Runtime: " << float(clock() - t) / CLOCKS_PER_SEC << " seconds\n";

#define TEST(x, solution) \
        { \
            clock_t t; \
            t = clock(); \
            Problem##x solver; \
            int64_t answer = solver.solve(); \
            if(answer == solution) \
                std::cout << "Problem " << x << " PASSED in:\t" << float(clock() - t) / CLOCKS_PER_SEC << " seconds\n"; \
            else \
            { \
                std::cout << "Problem " << x << " FAILED:\t" << answer << " != " << solution << "\n"; \
                return 0; \
            } \
        }

#define TEST_ALL() \
        clock_t t; \
        t = clock(); \
        TEST(1, 233168) \
        TEST(2, 4613732) \
        TEST(3, 6857) \
        TEST(4, 906609) \
        TEST(5, 232792560) \
        TEST(6, 25164150) \
        TEST(7, 104743) \
        TEST(8, 40824) \
        TEST(9, 31875000) \
        TEST(10, 142913828922) \
        TEST(11, 70600674) \
        TEST(12, 76576500) \
        TEST(13, 5537376230) \
        TEST(14, 837799) \
        TEST(15, 137846528820) \
        TEST(16, 1366) \
        TEST(17, 21124) \
        TEST(19, 171) \
        TEST(20, 648) \
        TEST(21, 31626) \
        TEST(22, 871198282) \
        TEST(23, 4179871) \
        TEST(24, 2783915460) \
        TEST(25, 4782) \
        TEST(26, 983) \
        TEST(27, -59231) \
        TEST(28, 669171001) \
        TEST(29, 9183) \
        TEST(30, 443839) \
        TEST(31, 73682) \
        TEST(32, 45228) \
        TEST(33, 100) \
        TEST(34, 40730) \
        TEST(35, 55) \
        TEST(36, 872187) \
        TEST(37, 748317) \
        TEST(38, 932718654) \
        TEST(39, 840) \
        TEST(40, 210) \
        TEST(41, 7652413) \
        TEST(42, 162) \
        TEST(43, 16695334890) \
        TEST(44, 5482660) \
        TEST(45, 1533776805) \
        TEST(46, 5777) \
        TEST(47, 134043) \
        TEST(48, 9110846700) \
        TEST(49, 296962999629) \
        TEST(50, 997651) \
        TEST(52, 142857) \
        TEST(55, 249) \
        TEST(56, 972) \
        TEST(58, 26241) \
        TEST(62, 127035954683) \
        TEST(63, 49) \
        TEST(71, 428570) \
        TEST(74, 402) \
        TEST(76, 190569291) \
        TEST(77, 71) \
        TEST(81, 427337) \
        TEST(82, 260324) \
        TEST(83, 425185) \
        TEST(92, 8581146) \
        std::cout << "Total time:\t" << float(clock() - t) / CLOCKS_PER_SEC << " seconds\n";

#endif /* defined(__ProjectEuler__Euler__) */
