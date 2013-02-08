<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>19:54:27</time>
  <numProcs>4</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>8.16556</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>124013</CallTime>
		<PhaseTime>1518733</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>6.42147</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>124013</CallTime>
		<LateTime>97525</LateTime>
		<PhaseTime>1518733</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>8.60533</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>130692</CallTime>
		<PhaseTime>1518733</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>6.84702</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>130692</CallTime>
		<LateTime>103988</LateTime>
		<PhaseTime>1518733</PhaseTime>
	</addInfo>
  </property>
</Experiment>
