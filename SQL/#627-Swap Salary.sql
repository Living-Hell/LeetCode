/*M1*/
update Salary set sex = if(sex = 'f', 'm', 'f');

/*M2*/
update Salary set sex = 
(case
    when sex = 'f' then 'm'
    else 'f'
end
);