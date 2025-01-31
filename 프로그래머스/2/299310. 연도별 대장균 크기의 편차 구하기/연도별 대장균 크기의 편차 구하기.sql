SELECT 
    YEAR(e.DIFFERENTIATION_DATE) AS year,
    (dev.max_colony_size - e.size_of_colony) AS year_dev,
    e.id
FROM ecoli_data e
JOIN (
    SELECT 
        YEAR(DIFFERENTIATION_DATE) AS year, 
        MAX(size_of_colony) AS max_colony_size
    FROM ecoli_data
    GROUP BY YEAR(DIFFERENTIATION_DATE)
) AS dev 
ON dev.year = YEAR(e.DIFFERENTIATION_DATE)
ORDER BY 
    year ASC, 
    year_dev ASC;
