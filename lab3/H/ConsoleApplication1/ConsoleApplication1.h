#pragma once

Cat* get_home_for_a_cats_pride(unsigned int n)
{
    Cat* cats = new Cat[n];
    for (unsigned int i = 0; i < n; i++)
    {
        *(*(cats + i)).name = new char[10];
    }
    return cats;
}
