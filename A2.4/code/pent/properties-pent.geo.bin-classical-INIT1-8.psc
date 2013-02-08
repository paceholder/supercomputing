<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-08</date>
  <time>14:29:28</time>
  <numProcs>8</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="8x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="2" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="0" thread="0"/>
	</context>
	<severity>9.50704</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="8x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="7" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>11.8468</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="8x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="2" thread="0"/>
		<execObj process="6" thread="0"/>
		<execObj process="0" thread="0"/>
	</context>
	<severity>9.22135</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="8x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="7" thread="0"/>
		<execObj process="4" thread="0"/>
	</context>
	<severity>11.5524</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
</Experiment>
