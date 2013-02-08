<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>21:39:09</time>
  <numProcs>64</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="true" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="64x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="12" thread="0"/>
		<execObj process="13" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="15" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="28" thread="0"/>
		<execObj process="20" thread="0"/>
		<execObj process="17" thread="0"/>
		<execObj process="26" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="27" thread="0"/>
		<execObj process="30" thread="0"/>
		<execObj process="22" thread="0"/>
		<execObj process="19" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="44" thread="0"/>
	</context>
	<severity>5.34204</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
  <property cluster="true" ID="7-179" >
	<name>Excessive MPI time in receive due to late sender</name>
	<context FileID="9" FileName="initialization.c" RFL="325" Config="64x1" Region="MPI_CALL" RegionId="9-325" >
		<execObj process="12" thread="0"/>
		<execObj process="13" thread="0"/>
		<execObj process="14" thread="0"/>
		<execObj process="1" thread="0"/>
		<execObj process="28" thread="0"/>
		<execObj process="20" thread="0"/>
		<execObj process="17" thread="0"/>
		<execObj process="26" thread="0"/>
		<execObj process="29" thread="0"/>
		<execObj process="21" thread="0"/>
		<execObj process="18" thread="0"/>
		<execObj process="27" thread="0"/>
		<execObj process="30" thread="0"/>
		<execObj process="22" thread="0"/>
		<execObj process="19" thread="0"/>
		<execObj process="31" thread="0"/>
		<execObj process="23" thread="0"/>
		<execObj process="25" thread="0"/>
		<execObj process="45" thread="0"/>
		<execObj process="46" thread="0"/>
		<execObj process="47" thread="0"/>
		<execObj process="44" thread="0"/>
	</context>
	<severity>5.34137</severity>
	<confidence>1</confidence>
	<addInfo>
	</addInfo>
  </property>
</Experiment>
