#!/usr/bin/env python
# coding: utf-8

# In[265]:


import requests 
from bs4 import BeautifulSoup
import re
import pandas as pd
import numpy as np


# In[266]:


url = 'https://www.dotabuff.com/heroes'
headers = {
    'Accept' : '*,*',
    'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 YaBrowser/23.1.0.2947 Yowser/2.5 Safari/537.36'
}
req = requests.get(url, headers = headers)
src = req.text

with open('index.html', 'w',  encoding = "utf-8") as file:
    file.write(src)


# In[267]:


with open('index.html', encoding = "utf-8") as file:
    src = file.read()
soup = BeautifulSoup(src, 'lxml')


# In[268]:


all_heroes = soup.find_all(class_ = 'name')
hero_names = []
hero_links = []
hero_counters_links = []
for i in all_heroes:
    hero_name = i.text
    hero_names.append(hero_name)
    hero_link = 'https://www.dotabuff.com/heroes' + '/' + str(hero_name).lower().replace(' ', '-')
    hero_links.append(hero_link)
    hero_counters_link = 'https://www.dotabuff.com/heroes' + '/' +     str(hero_name).lower().replace(' ', '-') + '/counters' 
    hero_counters_links.append(hero_counters_link)
name_and_link =  dict(zip(hero_names, hero_links))
name_and_counters_link = dict(zip(hero_names, hero_counters_links))


# In[269]:


def counters(name):
    link = name_and_counters_link[name]
    url = link
    headers = {
        'Accept' : '*/*',
        'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/108.0.0.0 YaBrowser/23.1.0.2947 Yowser/2.5 Safari/537.36'
    }
    req = requests.get(url, headers = headers)
    src = req.text
    soup = BeautifulSoup(src, 'lxml')
    
    all_info = []
    for t in soup.find('table', class_ = 'sortable').find_all('td'):
        if t.get('data-value') != None :
            all_info.append(t.get('data-value').split('/n')[0])
    counter_heroes = all_info[::4]
    disadvantage = list(map(lambda x : float(x), all_info[1::4]))
    
    return counter_heroes, disadvantage


# In[270]:


def counterpick(hero1, hero2 = None, hero3 = None, hero4 = None, hero5 = None):
    heroes = np.array([hero1, hero2, hero3, hero4, hero5])
    heroes = heroes[heroes != None]
    
    all_heroes_df = pd.DataFrame(data = [hero_names, np.array([0]* 123)]).T
    all_heroes_df = all_heroes_df.drop(index = all_heroes_df[all_heroes_df[0].isin(heroes)].index)        .reset_index(drop = True)
    
    for hero in heroes:
        counter_picks = pd.DataFrame(data = [counters(hero)[0], counters(hero)[1]]).T
        counter_picks = counter_picks.drop(index = counter_picks[counter_picks[0].isin(heroes)].index)        .reset_index(drop = True)
        counter_picks = counter_picks.sort_values(by = 0).reset_index(drop = True)
        all_heroes_df[1] = counter_picks[1] + all_heroes_df[1] 
        
    suggested_heroes = all_heroes_df.iloc[all_heroes_df[1].sort_values(ascending = False)                       .head(10).index][0].values
    not_suggested_heroes = all_heroes_df.iloc[all_heroes_df[1].sort_values(ascending = False)                       .tail(10).index][0].values
    return list(suggested_heroes), list(not_suggested_heroes)


# In[271]:


counterpick('Abaddon', 'Bristleback', 'Ember Spirit')


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




