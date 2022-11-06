select stock_name, 
sum(
case 
    when operation like 'BUY' then -price
    else +price
end)
as capital_gain_loss 
from Stocks
group by stock_name;