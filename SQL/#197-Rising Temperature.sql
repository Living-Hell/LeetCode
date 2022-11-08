select w.id 
from Weather w, Weather v 
where dateDiff(w.recordDate, v.recordDate) = 1 and w.temperature > v.temperature;