

#include "maxdefense.hh"
#include "timer.hh"


int main()
{
    
    auto all_armors = load_armor_database("armor.csv");
    auto filtered_armors = filter_armor_vector(*all_armors, 1, 2500, all_armors->size());
    
    ArmorVector resize2;
    ArmorVector resize4;
    ArmorVector resize8;
    ArmorVector resize16;
    
    for(int i = 0; i < 2; ++i)
    {
        resize2.push_back(filtered_armors->at(i));
    }
    for(int i = 0; i < 4; ++i)
    {
        resize4.push_back(filtered_armors->at(i));
    }
    for(int i = 0; i < 8; ++i)
    {
        resize8.push_back(filtered_armors->at(i));
    }
    for(int i = 0; i < 16; ++i)
    {
        resize16.push_back(filtered_armors->at(i));
    }
    
    std::unique_ptr<ArmorVector> soln;
    
    double elapsed;
    Timer timer;
    
    soln = greedy_max_defense(resize2, 5000);
    elapsed = timer.elapsed();
    std::cout << "GD5: Elapsed time in seconds: " << elapsed << std::endl;
    
    timer.reset();
    soln = greedy_max_defense(resize4, 5000);
    elapsed = timer.elapsed();
    std::cout << "GD50: Elapsed time in seconds: " << elapsed << std::endl;
    
    timer.reset();
    soln = greedy_max_defense(resize8, 5000);
    elapsed = timer.elapsed();
    std::cout << "GD500: Elapsed time in seconds: " << elapsed << std::endl;
    
    timer.reset();
    soln = greedy_max_defense(resize16, 5000);
    elapsed = timer.elapsed();
    std::cout << "GD5000: Elapsed time in seconds: " << elapsed << std::endl;
    
    
    timer.reset();
    soln = exhaustive_max_defense(resize2, 5000);
    elapsed = timer.elapsed();
    std::cout << "EX5: Elapsed time in seconds: " << elapsed << std::endl;
    
    timer.reset();
    soln = exhaustive_max_defense(resize4, 5000);
    elapsed = timer.elapsed();
    std::cout << "EX50: Elapsed time in seconds: " << elapsed << std::endl;
    
    timer.reset();
    soln = exhaustive_max_defense(resize8, 5000);
    elapsed = timer.elapsed();
    std::cout << "EX500: Elapsed time in seconds: " << elapsed << std::endl;
    
    timer.reset();
    soln = exhaustive_max_defense(resize16, 5000);
    elapsed = timer.elapsed();
    std::cout << "EX5000: Elapsed time in seconds: " << elapsed << std::endl;
    
    
	return 0;
}


