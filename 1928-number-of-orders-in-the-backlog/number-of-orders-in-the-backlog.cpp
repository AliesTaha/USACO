class Solution {
public:
    struct minheaper{
        bool operator()(const vector<int>& a, const vector<int>& b) const{
            return a[0]>b[0];
        }
    };

    struct maxheaper{
        bool operator()(const vector<int>& a, const vector<int>& b) const{
            return a[0]<b[0];
        }
    };

    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {

        priority_queue<vector<int>, vector<vector<int>>, minheaper> minheap_sell;
        priority_queue<vector<int>, vector<vector<int>>, maxheaper> maxheap_buy;

        for (auto &order: orders){
            int price=order[0],quantity=order[1];
            if (order[2]==0){ //buy
                while (quantity>0 && minheap_sell.size()>0){
                    int min_sell=minheap_sell.top()[0];
                    int min_sell_quantity=minheap_sell.top()[1];
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
                    int max_buy=maxheap_buy.top()[0];
                    int max_buy_quantity=maxheap_buy.top()[1];
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
            total+=minheap_sell.top()[1];
            minheap_sell.pop();
        }
        while (maxheap_buy.size()>0){
            total+=maxheap_buy.top()[1];
            maxheap_buy.pop();
        }
        return int(total%1'000'000'007);
        // return size of both heaps
    }
};