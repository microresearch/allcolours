/*
Templates with macros...

 */

case 0: // simplest CVspeed case
    if (counter[w]>speed[w]){
    dactype[2]=0; 
    GSHIFT;
      
    shift_[w]=shift_[w]<<1;
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    PULSIN_XOR;    
    shift_[w]+=bitn;
    
    dac[w]=DAC_(w, SRlength[w], dactype[w],0);
    PULSEOUT;
    }// counterw
  break; 

case 1: // template for different modes for N only and bitsin logic via logtable
    if (counter[w]>speed[w]){ 
    counter[w]=0; 
    dactype[2]=1; 
    logtable[0]=0; logtable[1]=1; logtable[2]=0; logtable[3]=1;
    
    Gshift_[w][0]=shift_[w]; 
    Gshift_[w][1]=shift_[w]; 
    Gshift_[w][2]=shift_[w];
    Gshift_[w][3]=shift_[w];

    shift_[w]=shift_[w]<<1;

    if (w==0){
      bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01;  
      Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      bitn^=ADC_(w,SRlength[w],2,0); 
    }
    else
      {
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  
      }

    if (pulsins[w]!=0){
    xx=!(GPIOC->IDR & pulsins[w]); 
    bitn=logop(bitn,xx,logtable[w]); 
    }
    
    shift_[w]+=bitn;
    
    dac[w]=DAC_(w, SRlength[w], dactype[w],0); 

    PULSEOUT;
  }// counterw
  break;

case 2: // INT mode/probability but no ADC in? - was case 11
    if (trigger[w]==1){ 
      dactype[2]=0; 

      Gshift_[w][0]=shift_[w]; 
      Gshift_[w][1]=shift_[w]; 
      Gshift_[w][2]=shift_[w];
      Gshift_[w][3]=shift_[w]; 
      
      shift_[w]=shift_[w]<<1;
      bitn=(shift_[w]>>SRlength[w])& 0x01; 
      if (pulsins[w]!=0) xx=!(GPIOC->IDR & pulsins[w]); 
      
      if ((LFSR_[w] & 4095 )<adc_buffer[lookupadc[w]]) { 
	bitn=bitn^1;
      }
      bitn|=xx;
      shift_[w]+=bitn;

    dac[w]=DAC_(w, SRlength[w], dactype[w],0); 
    PULSEOUT;
    }
    break; 

case 3: // speedfrom/CV.DAC template to test
if (counter[w]>(speed[w]+dac[speedfrom_[w]])){// add means we always slow down - other options (wrap, lookup)
  /*
  tmpt=(dac[speedfrom_[w]]>>2)-(1024-speed[w]));
  if (tmpt<0) tmpt=0; 

  tmpt= speed[w]-(dac[speedfrom_[w]]>>2);
  if (tmpt<0) tmpt=0; 

  if (counter[w]>((dac[speedfrom_[w]]>>2)%speed[w])){ // wrap

// 

   */
  
  dactype[2]=0; 

    counter[w]=0; 
    Gshift_[w][0]=shift_[w]; 
    Gshift_[w][1]=shift_[w]; 
    Gshift_[w][2]=shift_[w];
    Gshift_[w][3]=shift_[w]; 
      
    shift_[w]=shift_[w]<<1;
  
    bitn = (Gshift_[defroute[w]][w]>>SRlength[defroute[w]]) & 0x01; 
    Gshift_[defroute[w]][w]=(Gshift_[defroute[w]][w]<<1)+bitn;  

    if (pulsins[w]!=0){
    xx=!(GPIOC->IDR & pulsins[w]); 
    bitn^=xx;
    }
    
    shift_[w]+=bitn;
    
    dac[w]=DAC_(w, SRlength[w], dactype[w],0);
    PULSEOUT;
    }// counterw
  break; 


