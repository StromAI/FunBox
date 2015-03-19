clear;clc;close all;
uncode_sequence=[1 0 0 1 1 0 1 1 0 0 1]
sequence_length = length(uncode_sequence);
crc_ccitt=[1 0 0 1 1];
crc_length=length(crc_ccitt)-1;
add_bit = zeros(1,crc_length);
crc_coded_sequence = [uncode_sequence add_bit];
remainder_bits = [uncode_sequence add_bit];
for k = 1:sequence_length
    add_zeros = zeros(1,sequence_length-k);
    register_bits = [crc_ccitt add_zeros];
    if remainder_bits(1) == 0
        register_bits = zeros(1,length(register_bits));
    end
    remainder_bits = bitxor(register_bits,remainder_bits);

    
    register_bits = crc_ccitt;
    remainder_bits(1) = [];
end

crc_coded_sequence = [uncode_sequence remainder_bits] ;
                            

%error=randint(1,length(crc_coded_sequence));

%crc_coded_sequence=bitxor(crc_coded_sequence,error);

sequence_length = length(crc_coded_sequence);
original_sequence = crc_coded_sequence; 
crc_ccitt=[1 0 0 1 1];
remainder_bits = crc_coded_sequence;
cycle_length = sequence_length-length(crc_ccitt)+1;
 
for k = 1:cycle_length
    add_zeros = zeros(1,cycle_length-k);       
    register_bits = [crc_ccitt add_zeros];
    if remainder_bits(1) == 0     
        register_bits = zeros(1,length(register_bits));
    end
    remainder_bits = bitxor(register_bits,remainder_bits); 
    register_bits = crc_ccitt;
    remainder_bits(1) = [];
end

if sum(remainder_bits) == 0
    original_sequence = crc_coded_sequence(1:cycle_length)
else
    err = 1
end
        