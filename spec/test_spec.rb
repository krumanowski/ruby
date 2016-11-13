require 'simplecov'
SimpleCov.start

require './test'

RSpec.describe 'test.rb' do
  describe '#quicksort' do

#1    
    it 'sortowanie nie gubi danych' do
          expect(quicksort([5, 4, 3]))
          contain_exactly(3, 4, 5)
    end
#2    
    it 'prawidłowe sortowanie na intach' do
          expect(quicksort([3, 2, 1]))
          eq([1, 2, 3])
    end
#3    
    it 'prawidłowe sortowanie na floatach' do
          expect(quicksort([3.1, 2.3, 1.1]))
          eq([1.1, 2.3, 3.1])
    end
#4    
    it 'sortowanie na intach' do
          expect(quicksort([3, 2, 1]))
          eq([1, 2, 3])
    end
#5   
    it 'sortowanie na floatach' do
          expect(quicksort([3.0, 2.3, 1.9]))
          eq([1.9, 2.3, 3.0])
    end
#6    
    it 'prawidłowy string w tablicy' do
        expect(quicksort(%w(lorem ipsum dolor sit amet))).to eq(%w(amet dolor ipsum lorem sit))
    end
#7    
    it 'inty zwracają inty ' do
          expect { quicksort([5, 100, 200, -7]).to be_a_kind_of(integer) }
    end
#8    
    it 'floaty zwracają floaty' do
          expect { quicksort([5.0, 70.1, 20.23, -8.09]).to be_a_kind_of(float) }
    end
#9  
    it 'błędny string w tablicy' do
          expect(quicksort([0, 1, 2, "test"])).to raise_error 
    end
#10    
    it 'pusta tablica' do
          expect { quicksort([]).to be_a_kind_of(Boolean) }
    end  
  end
end

