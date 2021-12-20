#!/usr/bin/env python
from cyaron import * #

n_=ati([0,7,50,1e4]);
m_=ati([0,11,1000,1e4]);

for i in  range(1,4):
  test_data=IO(file_prefix='head',data_id=i);

  n=n_[i];
  m=m_[i];
  s=randint(1,n)
  t=randint(1,n)
  test_data.input_writeln(n,m,s,t);

  graph=Graph.graph(n,m,weight_limit=5);
  test_data.input_writeln(graph);
