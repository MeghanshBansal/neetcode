class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        if (n == 0) {
            return 0;
        }

        std::vector<std::pair<int, double>> cars_data(n);

        for (int i = 0; i < n; ++i) {
            double time_to_target = static_cast<double>(target - position[i]) / speed[i];
            cars_data[i] = {position[i], time_to_target};
        }

        std::sort(cars_data.begin(), cars_data.end());
        std::stack<double> fleet_times;
        for (int i = n - 1; i >= 0; --i) {
            double current_car_time = cars_data[i].second;

            if (fleet_times.empty() || current_car_time > fleet_times.top()) {
                fleet_times.push(current_car_time);
            }
        }

        return fleet_times.size();
    }
};
