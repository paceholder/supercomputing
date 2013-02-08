<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>22:55:17</time>
  <numProcs>8</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>14.5111</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>9.48909</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>314540</CallTime>
		<PhaseTime>3314754</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>13.4577</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>8.43725</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>314540</CallTime>
		<LateTime>279674</LateTime>
		<PhaseTime>3314754</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
		<execObj process="0" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="5" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>32.7877</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="5" thread="0"/>
		<execObj process="2" thread="0"/>
		<execObj process="3" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>28.5296</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>5.17746</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>171620</CallTime>
		<PhaseTime>3314750</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>38.2347</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1267386</CallTime>
		<PhaseTime>3314750</PhaseTime>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="7" thread="0"/>
		<execObj process="6" thread="0"/>
	</context>
	<severity>11.1105</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="7" thread="0"/>
		<execObj process="6" thread="0"/>
	</context>
	<severity>10.0576</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="8x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="6" thread="0"/>
		<execObj process="7" thread="0"/>
		<execObj process="2" thread="0"/>
	</context>
	<severity>30.3828</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
</Experiment>
