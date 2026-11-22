class Solution {
public:
    struct minheaper{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const{
            return a.first>b.first;
        }
    };

    struct maxheaper{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const{
            return a.first<b.first;
        }
    };

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {

        priority_queue<pair<int, int>, vector<pair<int, int>>, minheaper> minheap_sell;
        priority_queue<pair<int, int>, vector<pair<int, int>>, maxheaper> maxheap_buy;

        for (auto &order: orders){
            int price=order[0],quantity=order[1];
            if (order[2]==0){ //buy
                while (quantity>0 && minheap_sell.size()>0){
                    int min_sell=minheap_sell.top().first;
                    int min_sell_quantity=minheap_sell.top().second;
                    if (min_sell<=price){
                        int dec=min(quantity, min_sell_quantity);
                        quantity-=dec;
                        min_sell_quantity-=dec;
                        minheap_sell.pop();
                        if (min_sell_quantity>0){
                            minheap_sell.push({min_sell, min_sell_quantity});
                        }
                    }
                    else{
                        break;
                    }
                }
                if (quantity>0){
                    maxheap_buy.push({price, quantity});
                }
            }
            else{
                while (quantity>0 && maxheap_buy.size()>0){
                    int max_buy=maxheap_buy.top().first;
                    int max_buy_quantity=maxheap_buy.top().second;
                    if (max_buy>=price){
                        int dec=min(quantity, max_buy_quantity);
                        quantity-=dec;
                        max_buy_quantity-=dec;
                        maxheap_buy.pop();
                        if (max_buy_quantity>0){
                            maxheap_buy.push({max_buy, max_buy_quantity});
                        }
                    }
                    else{
                        break;
                    }
                }
                if (quantity>0){
                    minheap_sell.push({price, quantity});
                }
            }
        }

        long long total=0;
        while (minheap_sell.size()>0){
            total+=minheap_sell.top().second;
            minheap_sell.pop();
        }
        while (maxheap_buy.size()>0){
            total+=maxheap_buy.top().second;
            maxheap_buy.pop();
        }
        return int(total%1'000'000'007);
        // return size of both heaps
    }
};