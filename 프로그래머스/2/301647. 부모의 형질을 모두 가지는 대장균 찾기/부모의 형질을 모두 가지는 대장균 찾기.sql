select d.id, d.genotype, p.genotype as parent_genotype
from ecoli_data d
left join ecoli_data p
on d.parent_id = p.id
where (d.genotype & p.genotype) = p.genotype
order by d.id