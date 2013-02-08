<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>23:05:13</time>
  <numProcs>4</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>14.7296</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1089345</CallTime>
		<PhaseTime>7395610</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>14.2883</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1089345</CallTime>
		<LateTime>1056705</LateTime>
		<PhaseTime>7395610</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>29.0331</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2147174</CallTime>
		<PhaseTime>7395610</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>34.2851</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2535592</CallTime>
		<PhaseTime>7395610</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>19.5976</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1449357</CallTime>
		<PhaseTime>7395602</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>19.1506</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1449357</CallTime>
		<LateTime>1416301</LateTime>
		<PhaseTime>7395602</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>29.4771</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2180012</CallTime>
		<PhaseTime>7395602</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>28.5517</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2111572</CallTime>
		<PhaseTime>7395602</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>15.0473</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1112840</CallTime>
		<PhaseTime>7395607</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>14.603</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1112840</CallTime>
		<LateTime>1079984</LateTime>
		<PhaseTime>7395607</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>28.7607</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2127027</CallTime>
		<PhaseTime>7395607</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>32.3729</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2394175</CallTime>
		<PhaseTime>7395607</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>33.668</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>2489953</CallTime>
		<PhaseTime>7395606</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>46.3608</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>3428664</CallTime>
		<PhaseTime>7395606</PhaseTime>
	</addInfo>
  </property>
</Experiment>
