# 初识Django
[toc]

## 1. 模型设计
```python
#! mysite/news/models.py

from django.db import models

class Reporter(models.Model):
    full_name = models.CharField(max_length=70)

    def __str__(self):
        return self.full_name


class Article(models.Model):
    pub_date = models.DateField()
    headline = models.CharField(max_length=200)
    content = models.TextField()
    reporter = models.ForeignKey(Reporter, on_delete=models.CASCADE)

    def __str__(self):
        return self.headline
```

## 2. 应用数据模型

```bash
python manage.py makemigrations
python manage.py migrate
```

## 3. Django模板

### 1. 
