<?xml version="1.0" encoding="UTF-8"?>
<Experiment xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns="http://www.lrr.in.tum.de/Periscope" xsi:schemaLocation="http://www.lrr.in.tum.de/Periscope psc_properties.xsd ">

  <date>2013-02-07</date>
  <time>22:20:15</time>
  <numProcs>4</numProcs>
  <numThreads>1</numThreads>
  <dir>/home/hpc/h039u/h039uan/supercomputing/A2.4/code</dir>
  <sir>./gccg.sir</sir>

  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>11.9558</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>3798262</CallTime>
		<PhaseTime>31769190</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>11.7833</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>3798262</CallTime>
		<LateTime>3743472</LateTime>
		<PhaseTime>31769190</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>28.0623</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>8915166</CallTime>
		<PhaseTime>31769190</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="0" thread="0"/>
	</context>
	<severity>33.9757</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>10793804</CallTime>
		<PhaseTime>31769190</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>5.71386</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1815243</CallTime>
		<PhaseTime>31769139</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>5.54193</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>1815243</CallTime>
		<LateTime>1760624</LateTime>
		<PhaseTime>31769139</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>28.0111</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>8898870</CallTime>
		<PhaseTime>31769139</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="1" thread="0"/>
	</context>
	<severity>41.8108</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>13282932</CallTime>
		<PhaseTime>31769139</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>12.9701</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>4120509</CallTime>
		<PhaseTime>31769172</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>12.7988</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>4120509</CallTime>
		<LateTime>4066085</LateTime>
		<PhaseTime>31769172</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>28.0144</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>8899934</CallTime>
		<PhaseTime>31769172</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="2" thread="0"/>
	</context>
	<severity>32.6447</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>10370952</CallTime>
		<PhaseTime>31769172</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_ALLREDUCE</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>12.676</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>4027061</CallTime>
		<PhaseTime>31769163</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-187" >
	<name>Excessive MPI time due to late process in allreduce</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>12.5039</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>4027061</CallTime>
		<LateTime>3972380</LateTime>
		<PhaseTime>31769163</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>25.9764</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>8252479</CallTime>
		<PhaseTime>31769163</PhaseTime>
	</addInfo>
  </property>
  <property cluster="false" ID="7-172" >
	<name>Excessive MPI communication time in MPI_RECV</name>
	<context FileID="9" FileName="compute_solution.c" RFL="17" Config="4x1" Region="MPI_CALL" RegionId="9-17" >
		<execObj process="3" thread="0"/>
	</context>
	<severity>35.3347</severity>
	<confidence>1</confidence>
	<addInfo>
		<CallTime>11225525</CallTime>
		<PhaseTime>31769163</PhaseTime>
	</addInfo>
  </property>
</Experiment>
